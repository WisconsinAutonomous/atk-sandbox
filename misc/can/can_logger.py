from canlib import canlib, kvadblib

import argparse
from pathlib import Path

BITRATES = {
    '1M': canlib.Bitrate.BITRATE_1M,
    '500K': canlib.Bitrate.BITRATE_500K,
    '250K': canlib.Bitrate.BITRATE_250K,
    '125K': canlib.Bitrate.BITRATE_125K,
    '100K': canlib.Bitrate.BITRATE_100K,
    '62K': canlib.Bitrate.BITRATE_62K,
    '50K': canlib.Bitrate.BITRATE_50K,
    '83K': canlib.Bitrate.BITRATE_83K,
    '10K': canlib.Bitrate.BITRATE_10K,
}


class CANBusConfig:
    dbc: Path

    channel: int
    bitrate: str

    signals: list


class CANBus:
    """Helper class that abstracts kvadblib stuff

    Loads a dbc file and will read data from a can bus using the dbc specficiation
    """

    def __init__(self, config: CANBusConfig):
        self.config = config

        # Print out the channel data (debug purposes)
        self._print_channel_data()

        # Load the dbc file
        print(
            f"Loading '{self.config.dbc.name}' as a DBC file...")
        self.db = kvadblib.Dbc(filename=self.config.dbc)
        print(
            f"Opened '{self.config.dbc.name}' as a DBC file.")

        # Open the channel
        self._open_channel()

        # Create an empty framebox
        self.framebox = kvadblib.FrameBox(self.db)

        # Add all message to the framebox, as we may receive any signal
        for msg in self.db:
            self.framebox.add_message(msg.name)

    def _print_channel_data(self):
        """Helper method to print out channel data."""

        for ch in range(canlib.getNumberOfChannels()):
            chdata = canlib.ChannelData(ch)

            name = chdata.channel_name
            ean = chdata.card_upc_no
            serial = chdata.card_serial_no

            print(
                f"canlib.ChannelData: {ch}. {name} ({ean} / {serial})")

    def _open_channel(self):
        """Helper method to open a can bus channel."""

        # Check the channel number is in range
        if self.config.channel not in range(canlib.getNumberOfChannels()):
            print(
                f"Channel number '{self.config.channel}' not available.")
            exit(-1)

        # Get the bitrate
        if self.config.bitrate not in BITRATES:
            print(
                f"Bitrate '{self.config.bitrate}' not available.")
            exit(-1)
        bitrate = BITRATES[self.config.bitrate]

        print(f"Opening channel {self.config.channel}...")

        # Open the channel
        flags = 0
        self.ch = canlib.openChannel(
            self.config.channel, bitrate=bitrate, flags=flags)
        self.ch.setBusOutputControl(canlib.canDRIVER_NORMAL)
        self.ch.busOn()

        print(f"Opened channel {self.config.channel}.")

    def spin(self, timeout: float = 0.5):
        """Read the frames from the bus"""

        # Read each frame from the bus
        while True:
            try:
                frame = self.ch.read(timeout=int(timeout * 1000))
                self.print_frame(frame)
            except canlib.CanNoMsg:
                print("No Can Message. Trying again...")
            except KeyboardInterrupt:
                print("Keyboard Interrupt Received.")
                break

    def print_frame(self, frame):
        try:
            bmsg = self.db.interpret(frame)
        except kvadblib.KvdNoMessage:
            print(f"<<< No message found for frame with id {frame.id} >>>")
            return

        if not bmsg._message.dlc == bmsg._frame.dlc:
            print(
                "<<< Could not interpret message because DLC does not match for"
                f" frame with id {frame.id} >>>"
            )
            print(f"\t- DLC (database): {bmsg._message.dlc}")
            print(f"\t- DLC (received frame): {bmsg._frame.dlc}")
            return

        msg = bmsg._message

        if self.config.signals and msg.name not in self.config.signals:
            return

        print('┏', msg.name)

        if msg.comment:
            print('┃', f'"{msg.comment}"')

        for bsig in bmsg:
            print('┃', bsig.name + ':', bsig.value, bsig.unit)

        print('┗')


if __name__ == "__main__":
    parser = argparse.ArgumentParser(description="CAN Logger")

    parser.add_argument("--dbc", type=str, help="DBC file.",
                        default="Scoring_Year1.dbc")
    parser.add_argument("--channel", type=int, help="CAN Channel", default=0)
    parser.add_argument("--bitrate", type=str, help="CAN Bitrate",
                        default="250K", choices=BITRATES.keys())

    parser.add_argument("-s", "--signals", nargs="+",
                        help="Filtered Signals. If empty, will show all.", default=[])

    args = parser.parse_args()

    config = CANBusConfig()
    config.dbc = Path(args.dbc)
    config.channel = args.channel
    config.bitrate = args.bitrate
    config.signals = args.signals

    bus = CANBus(config)
    bus.spin()
