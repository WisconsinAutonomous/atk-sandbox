# Import some classes from the autonomy_toolkit module
from autonomy_toolkit.db import ATKDataFileReader, register_type
from autonomy_toolkit.utils.logger import LOGGER

# Utility imports
from util import register_all_msg_files

# Other imports
import argparse
import cv2
from pathlib import Path
import numpy as np

if __name__ == "__main__":
    parser = argparse.ArgumentParser(
        description="Save images in a bag file to a video format")

    parser.add_argument("bag", help="The bag file to load data from", type=str)
    parser.add_argument(
        "topic", help="The topic which has sensor_msgs/msg/Image msgs on it", type=str)
    parser.add_argument(
        "-o", "--out", help="Output file to save to. Output type is ALWAYS {out}.avi.", default="out")
    parser.add_argument(
        "-f", "--fps", help="FPS of the saved video.", type=int, default=15.0)

    args = parser.parse_args()

    bag = args.bag
    topic = args.topic

    print("Writing...")
    with ATKDataFileReader(args.bag) as reader:

        # Get height and width of first image with that topic
        height = width = -1
        for timestamp, connection, msg in reader:
            if topic == connection.topic:
                height = msg.height
                width = msg.width

        if height == -1:
            LOGGER.error(f"Cannot find {topic} in {bag}")
            return

        # Use cv2 to save images
        fourcc = cv2.VideoWriter_fourcc(*"MJPG")
        video = cv2.VideoWriter(
            f"{args.out}.avi", fourcc, args.fps, (width, height))

        for timestamp, connection, msg in reader:
            if topic == connection.topic:
                im = np.ndarray(shape=(msg.height, msg.width, 3),
                                dtype=np.uint8, buffer=msg.data)
                video.write(im)
    print("Done.")

    video.release()
