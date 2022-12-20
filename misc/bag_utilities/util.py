def search_upwards_for_files(root: 'Tuple[Path, str]', ext: str) -> dict:
    """Search for files upward with a certain extension"""
    import os
    from pathlib import Path

    list_of_files = {}
    for (dirpath, dirnames, filenames) in os.walk(root):
        for filename in filenames:
            if filename.endswith(ext):
                list_of_files[filename] = Path(
                    os.sep.join([dirpath, filename]))

    return list_of_files


def register_all_msg_files(start_dir: 'Tuple[Path,str]' = '../../workspace/src'):
    """Register all msg files in a workspace

    Will begin walking through all subdirectories starting at `start_dir` and register
    all msg files with atk
    """
    from autonomy_toolkit.db import register_type
    from rosbags.typesys.base import TypesysError
    from autonomy_toolkit.utils.logger import LOGGER
    from pathlib import Path

    msg_files = search_upwards_for_files(start_dir, ".msg")

    while len(msg_files) != 0:
        for name, path in msg_files.items():
            name = f"{path.parent.parent.name}/msg/{Path(name).with_suffix('')}"
            try:
                register_type(path, name)
            except TypesysError as e:
                LOGGER.warn(f"Failed to register type {name}")
