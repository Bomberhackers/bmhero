#!/usr/bin/env python3

def apply(config, args):
    config['baseimg'] = 'baserom.z64'
    config['myimg'] = 'build/bmhero.z64'
    config['mapfile'] = 'build/bmhero.map'
    config['source_directories'] = ['.']
    config["objdump_flags"] = ["-Mreg-names=32"]
