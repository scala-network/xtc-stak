# HowTo Use xtl-stak

## Content Overview
* [Configuration](#configuration)
* [Usage on Windows](#usage-on-windows)
* [Usage on Linux](#usage-on-linux)
* [Command Line Options](#command-line-options)
* [Use different backends](#use-different-backends)
* [HTML and JSON API report configuraton](#html-and-json-api-report-configuraton)

## Configurations

Before you started the miner the first time there are no config files available.
Config files will be created at the first start.
The number of files depends on the available backends.
`config.txt` contains the common miner settings.
`pools.txt` contains the selected mining pools and currency to mine.
`amd.txt`, `cpu.txt` and `nvidia.txt` contains miner backend specific settings and can be used for further tuning ([Tuning Guide](tuning.md)).

Note: If the pool is ignoring the option `rig_id` in `pools.txt` to name your worker please check the pool documentation how a worker name can be set.

## Usage on Windows
1) Double click the `xtl-stak.exe` file
2) Fill in the pool url settings, currency, username and password

`set XMRSTAK_NOWAIT=1` disable the dialog `Press any key to exit.` for non UAC execution.


## Usage on Linux & macOS
1) Open a terminal within the folder with the binary
2) Start the miner with `./xtl-stak`

## Command Line Options

The miner allow to overwrite some of the settings via command line options.
Run `xtl-stak --help` to show all available command line options.

## Use Different Backends

On linux and OSX please add `./` before the binary name `xtl-stak`.

### CPU Only:
```
xtl-stak --noAMD --noNVIDIA
```

### NVIDIA/AMD Only:

The miner will automatically detect if CUDA (for NVIDIA GPUs) or OpenCL (for AMD GPUs) is available.

```
xtl-stak --noCPU
```
**CUDA** is currently not supported. I am currently try to get some performance out it.

### NVIDIA via OpenCL

It is possible to use the OpenCl backend which is originally created for AMD GPUs with NVIDIA GPus.
Some NVIDIA GPUs can reach better performance with this backend.

```
xtl-stak --openCLVendor NVIDIA --noNVIDIA
```

## Docker image usage

You can run the Docker image the following way:

```
docker run --rm -it -u $(id -u):$(id -g) --name stellitecoin/xtl-stak -v "$PWD":/mnt xtl-stak
docker stop xtl-stak
docker run --rm -it -u $(id -u):$(id -g) --name stellitecoin/xtl-stak -v "$PWD":/mnt xtl-stak --config config.txt
```

Debug the docker image by getting inside:

```
docker run --entrypoint=/bin/bash --rm -it -u $(id -u):$(id -g) --name stellitecoin/xtl-stak -v "$PWD":/mnt xtl-stak
```

## HTML and JSON API report configuraton

To configure the reports shown on the [README](../README.md) side you need to edit the httpd_port variable. Then enable wifi on your phone and navigate to [miner ip address]:[httpd_port] in your phone browser. If you want to use the data in scripts, you can get the JSON version of the data at url [miner ip address]:[httpd_port]/api.json
