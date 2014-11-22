bin_PROGRAMS=pacserver
pacserver_SOURCES=pacserver.c socklib.c socklib.h
confdir=$(sysconfdir)/pacserver
conf_DATA=pac.txt
dist_data_DATA=pac.txt
pacserver_CFLAGS=-DCONFDIR=\"$(confdir)\"
