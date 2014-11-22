PAC File Host Server
====================
A simple pac file host server for linux with C. 


### Features

1. Easy to use. 
2. Only one option you can choose and simply use.
3. Use clowwindy's pac file, faster than you want.
4. Local host, you can share this server to LAN.

### Download

Download [latest release](/releases/latest).

### Quick Start

#### Install Binaries

1. Download pac-server-binaries-[version].tar.gz from release page.
2. tar xvf pac-server-binaries-[version].tar.gz
3. Copy bin/pacserver to /usr/local/bin.
4. Copy conf/pac.txt to /usr/local/etc/pacserver.
5. Run pacserver. 

#### Install By Source

See [BUILD](#build).

### Usage

	pacserver [port]
		port is an alternative option. if ignored, 9999 by default.
	PAC file default path is /usr/local/share/pacserver.


### BUILD

1. Download the latest source archive from github.
2. tar xvf pac-server-[version].tar.gz
3. cd pac-server-[version]
4. ./configure
5. make & sudo make install
6. Run and enjoy it!


### License  

GPLv3




