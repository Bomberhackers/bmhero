import os

def apply(config, args):
    basename = 'bmhero'
    if os.path.exists(f'build/{basename}.bin'):
        version = 'us'
    elif os.path.exists(f'build/{basename}.eu.bin'):
        version = 'eu'
    else:
        version = 'us'

    config['baseimg'] = f'baserom.z64'
    config['myimg'] = f'build/{basename}.z64'
    config['mapfile'] = f'build/{basename}.map'
    config['source_directories'] = ['src', 'include']
