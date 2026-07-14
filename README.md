# pi-dogdoor
Image detection dog door driver for RPi.

# Rapsberry Pi Setup Resources
- OpenCV Install 
    - https://github.com/Qengineering/Install-OpenCV-Raspberry-Pi-32-bits/tree/main
    - Use the latest version
    - Remove `libatlas-base-dev`. No longer supported.
    - `v4l2-ctl --list-devices`
- MobileNetSSD Dataset
    - https://github.com/PINTO0309/MobileNet-SSD-RealSense/tree/master/caffemodel/MobileNetSSD
    - Make sure installed files are binary.
- WiringPi
    - This is easier to use than the official library.
    - Installation and Examples ttps://docs.sunfounder.com/projects/raphael-kit/en/latest/c_pi5/play_with_c.html
    - Pinout https://pinout.xyz/pinout/wiringpi

# Raspberry Pi Info
`raspinfo`
System Information
------------------

Raspberry Pi 5 Model B Rev 1.0
PRETTY_NAME="Debian GNU/Linux 13 (trixie)"
NAME="Debian GNU/Linux"
VERSION_ID="13"
VERSION="13 (trixie)"

Raspberry Pi reference 2026-06-18
Generated using pi-gen, https://github.com/RPi-Distro/pi-gen, ca8aeed0ae300c2a89f55ce9617d5f96a27e99e5, stage4

Linux pi-dogdoor 6.18.34+rpt-rpi-2712 #1 SMP PREEMPT Debian 1:6.18.34-1+rpt1 (2026-06-09) aarch64 GNU/Linux
Revision	: d04170
Serial		: 1e5b5e36016eae90
Model		: Raspberry Pi 5 Model B Rev 1.0
Throttled flag  : throttled=0x0
Camera Information
------------------

Camera          : vc_gencmd_read_response returned -1 error=1 error_msg="Command not registered"

Videocore information
---------------------

2026/05/26 16:01:25 
Copyright (c) 2012 Broadcom
version 086b83e3 (release) (embedded)

vc_gencmd_read_response returned -1
error=1 error_msg="Command not registered"

Filesystem information
----------------------

Filesystem     1K-blocks     Used Available Use% Mounted on
udev             4082928        0   4082928   0% /dev
tmpfs            1651184    13616   1637568   1% /run
/dev/mmcblk0p2  29486280 11052352  17161740  40% /
tmpfs            4127936      416   4127520   1% /dev/shm
tmpfs               5120       64      5056   2% /run/lock
tmpfs               1024        0      1024   0% /run/credentials/systemd-journald.service
tmpfs            4127936   121360   4006576   3% /tmp
/dev/mmcblk0p1    516204    88909    427295  18% /boot/firmware
tmpfs             825584      256    825328   1% /run/user/1000
tmpfs               1024        0      1024   0% /run/credentials/getty@tty1.service
tmpfs               1024        0      1024   0% /run/credentials/serial-getty@ttyAMA10.service

Filename				Type		Size		Used		Priority
/dev/zram0                              partition	2097136		0		100

Package version information
---------------------------

raspberrypi-ui-mods:
  Installed: (none)
raspberrypi-sys-mods:
  Installed: 1:20260612
openbox:
  Installed: 3.6.1-12+rpt1
lxpanel:
  Installed: (none)
pcmanfm:
  Installed: 1.4.0-1+rpt9
rpd-plym-splash:
  Installed: 0.47

Networking Information
----------------------

Inter-| sta-|   Quality        |   Discarded packets               | Missed | WE
 face | tus | link level noise |  nwid  crypt   frag  retry   misc | beacon | 22
 wlan0: 0000   58.  -52.  -256        0      0      0      0      0        0

0: hci0: Bluetooth
	Soft blocked: no
	Hard blocked: no
1: phy0: Wireless LAN
	Soft blocked: no
	Hard blocked: no

eth0: flags=4099<UP,BROADCAST,MULTICAST>  mtu 1500
        ether m.m.m.m  txqueuelen 1000  (Ethernet)
        RX packets 0  bytes 0 (0.0 B)
        RX errors 0  dropped 0  overruns 0  frame 0
        TX packets 0  bytes 0 (0.0 B)
        TX errors 0  dropped 0 overruns 0  carrier 0  collisions 0
        device interrupt 106  

Settings for eth0:
	Supported ports: [ TP	 MII ]
	Supported link modes:   10baseT/Half 10baseT/Full
	                        100baseT/Half 100baseT/Full
	                        1000baseT/Half 1000baseT/Full
	Supported pause frame use: Transmit-only
	Supports auto-negotiation: Yes
	Supported FEC modes: Not reported
	Advertised link modes:  10baseT/Half 10baseT/Full
	                        100baseT/Half 100baseT/Full
	                        1000baseT/Half 1000baseT/Full
	Advertised pause frame use: Transmit-only
	Advertised auto-negotiation: Yes
	Advertised FEC modes: Not reported
	Speed: Unknown!
	Duplex: Unknown! (255)
	Auto-negotiation: on
	master-slave cfg: preferred slave
	master-slave status: unknown
	Port: Twisted Pair
	PHYAD: 1
	Transceiver: external
	MDI-X: Unknown
	Supports Wake-on: ag
	Wake-on: d
	Link detected: no

EEE settings for eth0:
	EEE status: enabled - inactive
	Tx LPI: 250000 (us)
	Supported EEE link modes:  100baseT/Full
	                           1000baseT/Full
	Advertised EEE link modes:  100baseT/Full
	                            1000baseT/Full
	Link partner advertised EEE link modes:  Not reported

NIC statistics:
     tx_octets: 0
     tx_frames: 0
     tx_broadcast_frames: 0
     tx_multicast_frames: 0
     tx_pause_frames: 0
     tx_64_byte_frames: 0
     tx_65_127_byte_frames: 0
     tx_128_255_byte_frames: 0
     tx_256_511_byte_frames: 0
     tx_512_1023_byte_frames: 0
     tx_1024_1518_byte_frames: 0
     tx_greater_than_1518_byte_frames: 0
     tx_underrun: 0
     tx_single_collision_frames: 0
     tx_multiple_collision_frames: 0
     tx_excessive_collisions: 0
     tx_late_collisions: 0
     tx_deferred_frames: 0
     tx_carrier_sense_errors: 0
     rx_octets: 0
     rx_frames: 0
     rx_broadcast_frames: 0
     rx_multicast_frames: 0
     rx_pause_frames: 0
     rx_64_byte_frames: 0
     rx_65_127_byte_frames: 0
     rx_128_255_byte_frames: 0
     rx_256_511_byte_frames: 0
     rx_512_1023_byte_frames: 0
     rx_1024_1518_byte_frames: 0
     rx_greater_than_1518_byte_frames: 0
     rx_undersized_frames: 0
     rx_oversize_frames: 0
     rx_jabbers: 0
     rx_frame_check_sequence_errors: 0
     rx_length_field_frame_errors: 0
     rx_symbol_errors: 0
     rx_alignment_errors: 0
     rx_resource_errors: 0
     rx_overruns: 0
     rx_ip_header_checksum_errors: 0
     rx_tcp_checksum_errors: 0
     rx_udp_checksum_errors: 0
     rx_lpi_transitions: 0
     rx_lpi_time: 0
     tx_lpi_transitions: 0
     tx_lpi_time: 0
     q0_rx_packets: 0
     q0_rx_bytes: 0
     q0_rx_dropped: 0
     q0_tx_packets: 0
     q0_tx_bytes: 0
     q0_tx_dropped: 0

wlan0: flags=4163<UP,BROADCAST,RUNNING,MULTICAST>  mtu 1500
        inet x.x.x.x  netmask x.x.x.x  broadcast x.x.x.x
        inet6 2600:1702:4ca0:y::y.y.y.y  prefixlen 128  scopeid 0x0<global>
        inet6 y::y.y.y.y  prefixlen 64  scopeid 0x20<link>
        ether m.m.m.m  txqueuelen 1000  (Ethernet)
        RX packets 32698  bytes 8728696 (8.3 MiB)
        RX errors 0  dropped 3  overruns 0  frame 0
        TX packets 32720  bytes 17998121 (17.1 MiB)
        TX errors 0  dropped 0 overruns 0  carrier 0  collisions 0

driver: brcmfmac
version: 7.45.16.144
firmware-version: 01-b677b91b
expansion-rom-version: 
bus-info: mmc1:0001:1
supports-statistics: no
supports-test: no
supports-eeprom-access: no
supports-register-dump: no
supports-priv-flags: no


USB Information
---------------

/:  Bus 001.Port 001: Dev 001, Class=root_hub, Driver=xhci-hcd/2p, 480M
/:  Bus 002.Port 001: Dev 001, Class=root_hub, Driver=xhci-hcd/1p, 5000M
/:  Bus 003.Port 001: Dev 001, Class=root_hub, Driver=xhci-hcd/2p, 480M
    |__ Port 001: Dev 002, If 0, Class=Video, Driver=uvcvideo, 480M
    |__ Port 001: Dev 002, If 1, Class=Video, Driver=uvcvideo, 480M
    |__ Port 001: Dev 002, If 2, Class=Video, Driver=uvcvideo, 480M
    |__ Port 001: Dev 002, If 3, Class=Audio, Driver=snd-usb-audio, 480M
    |__ Port 001: Dev 002, If 4, Class=Audio, Driver=snd-usb-audio, 480M
/:  Bus 004.Port 001: Dev 001, Class=root_hub, Driver=xhci-hcd/1p, 5000M

Display Information
-------------------

Using labwc with kms
Connector 0 (35) HDMI-A-1 (disconnected)
  Encoder 0 (34) TMDS
Connector 1 (44) HDMI-A-2 (disconnected)
  Encoder 1 (43) TMDS


Connector 0 (35) HDMI-A-1 (disconnected)
    EDID (1) = blob-id 0 (immutable)
    DPMS (2) = 0 (On) [On=0|Standby=1|Suspend=2|Off=3]
    TILE (4) = blob-id 0 (immutable)
    link-status (5) = 0 (Good) [Good=0|Bad=1]
    non-desktop (6) = 0 [0 - 1] (immutable)
    HDR_OUTPUT_METADATA (7) = blob-id 0
    CRTC_ID (20) = object id 0
    max bpc (36) = 8 [8 - 12]
    left margin (37) = 0 [0 - 100]
    right margin (38) = 0 [0 - 100]
    top margin (39) = 0 [0 - 100]
    bottom margin (40) = 0 [0 - 100]
    Colorspace (41) = 0 (Default) [Default=0|SMPTE_170M_YCC=1|BT709_YCC=2|XVYCC_601=3|XVYCC_709=4|SYCC_601=5|opYCC_601=6|opRGB=7|BT2020_CYCC=8|BT2020_RGB=9|BT2020_YCC=10|DCI-P3_RGB_D65=11|DCI-P3_RGB_Theater=12]
    Broadcast RGB (42) = 0 (Automatic) [Automatic=0|Full=1|Limited 16:235=2]
  Encoder 0 (34) TMDS
Connector 1 (44) HDMI-A-2 (disconnected)
    EDID (1) = blob-id 0 (immutable)
    DPMS (2) = 0 (On) [On=0|Standby=1|Suspend=2|Off=3]
    TILE (4) = blob-id 0 (immutable)
    link-status (5) = 0 (Good) [Good=0|Bad=1]
    non-desktop (6) = 0 [0 - 1] (immutable)
    HDR_OUTPUT_METADATA (7) = blob-id 0
    CRTC_ID (20) = object id 0
    left margin (37) = 0 [0 - 100]
    right margin (38) = 0 [0 - 100]
    top margin (39) = 0 [0 - 100]
    bottom margin (40) = 0 [0 - 100]
    max bpc (45) = 8 [8 - 12]
    Colorspace (46) = 0 (Default) [Default=0|SMPTE_170M_YCC=1|BT709_YCC=2|XVYCC_601=3|XVYCC_709=4|SYCC_601=5|opYCC_601=6|opRGB=7|BT2020_CYCC=8|BT2020_RGB=9|BT2020_YCC=10|DCI-P3_RGB_D65=11|DCI-P3_RGB_Theater=12]
    Broadcast RGB (47) = 0 (Automatic) [Automatic=0|Full=1|Limited 16:235=2]
  Encoder 1 (43) TMDS

/sys/class/drm/card1-HDMI-A-1

/sys/class/drm/card1-HDMI-A-2

/sys/class/drm/card1-Writeback-1

/sys/class/drm/card1-Writeback-2

HDMI0:             HDMI_HOTPLUG = 0x00000000
HDMI1:             HDMI_HOTPLUG = 0x00000000


Audio Information
-------------------

**** List of PLAYBACK Hardware Devices ****
card 0: vc4hdmi0 [vc4-hdmi-0], device 0: MAI PCM i2s-hifi-0 [MAI PCM i2s-hifi-0]
  Subdevices: 1/1
  Subdevice #0: subdevice #0
card 1: vc4hdmi1 [vc4-hdmi-1], device 0: MAI PCM i2s-hifi-0 [MAI PCM i2s-hifi-0]
  Subdevices: 1/1
  Subdevice #0: subdevice #0

null
    Discard all samples (playback) or generate zero samples (capture)
default
    Default Audio Device
sysdefault
    Default Audio Device
hw:CARD=vc4hdmi0,DEV=0
    vc4-hdmi-0, MAI PCM i2s-hifi-0
    Direct hardware device without any conversions
plughw:CARD=vc4hdmi0,DEV=0
    vc4-hdmi-0, MAI PCM i2s-hifi-0
    Hardware device with all software conversions
default:CARD=vc4hdmi0
    vc4-hdmi-0, MAI PCM i2s-hifi-0
    Default Audio Device
sysdefault:CARD=vc4hdmi0
    vc4-hdmi-0, MAI PCM i2s-hifi-0
    Default Audio Device
hdmi:CARD=vc4hdmi0,DEV=0
    vc4-hdmi-0, MAI PCM i2s-hifi-0
    HDMI Audio Output
dmix:CARD=vc4hdmi0,DEV=0
    vc4-hdmi-0, MAI PCM i2s-hifi-0
    Direct sample mixing device
hw:CARD=vc4hdmi1,DEV=0
    vc4-hdmi-1, MAI PCM i2s-hifi-0
    Direct hardware device without any conversions
plughw:CARD=vc4hdmi1,DEV=0
    vc4-hdmi-1, MAI PCM i2s-hifi-0
    Hardware device with all software conversions
default:CARD=vc4hdmi1
    vc4-hdmi-1, MAI PCM i2s-hifi-0
    Default Audio Device
sysdefault:CARD=vc4hdmi1
    vc4-hdmi-1, MAI PCM i2s-hifi-0
    Default Audio Device
hdmi:CARD=vc4hdmi1,DEV=0
    vc4-hdmi-1, MAI PCM i2s-hifi-0
    HDMI Audio Output
dmix:CARD=vc4hdmi1,DEV=0
    vc4-hdmi-1, MAI PCM i2s-hifi-0
    Direct sample mixing device

● pipewire.socket - PipeWire Multimedia System Sockets
     Loaded: loaded (/usr/lib/systemd/user/pipewire.socket; enabled; preset: enabled)
     Active: active (running) since Sun 2026-07-12 21:05:03 CDT; 39min ago
 Invocation: 912ea350c896457c9c0b3b5ba99dd64b
   Triggers: ● pipewire.service
     Listen: /run/user/1000/pipewire-0 (Stream)
             /run/user/1000/pipewire-0-manager (Stream)
     CGroup: /user.slice/user-1000.slice/user@1000.service/app.slice/pipewire.socket

Jul 12 21:05:03 pi-dogdoor systemd[1028]: Listening on pipewire.socket - PipeWire Multimedia System Sockets.

● pipewire.service - PipeWire Multimedia Service
     Loaded: loaded (/usr/lib/systemd/user/pipewire.service; enabled; preset: enabled)
     Active: active (running) since Sun 2026-07-12 21:05:03 CDT; 39min ago
 Invocation: 5bba063ec1de4d47ae5b44f89638f35b
TriggeredBy: ● pipewire.socket
   Main PID: 1059 (pipewire)
      Tasks: 3 (limit: 9626)
        CPU: 40ms
     CGroup: /user.slice/user-1000.slice/user@1000.service/session.slice/pipewire.service
             └─1059 /usr/bin/pipewire

Jul 12 21:05:03 pi-dogdoor systemd[1028]: Started pipewire.service - PipeWire Multimedia Service.
Jul 12 21:05:03 pi-dogdoor pipewire[1059]: mod.rt: RTKit error: org.freedesktop.DBus.Error.ServiceUnknown
Jul 12 21:05:03 pi-dogdoor pipewire[1059]: mod.rt: RTKit does not give us MaxRealtimePriority, using 1
Jul 12 21:05:03 pi-dogdoor pipewire[1059]: mod.rt: RTKit error: org.freedesktop.DBus.Error.ServiceUnknown
Jul 12 21:05:03 pi-dogdoor pipewire[1059]: mod.rt: RTKit does not give us MinNiceLevel, using 0
Jul 12 21:05:03 pi-dogdoor pipewire[1059]: mod.rt: RTKit error: org.freedesktop.DBus.Error.ServiceUnknown
Jul 12 21:05:03 pi-dogdoor pipewire[1059]: mod.rt: RTKit does not give us RTTimeUSecMax, using -1

pactl not installed

Firmware Configuration
----------------------

arm_64bit=1
arm_boost=1
arm_freq=2400
arm_freq_min=1500
arm_peri_high=1
audio_pwm_mode=2
auto_initramfs=1
avs_temp=39478
camera_auto_detect=1
core_freq=910
core_freq_min=500
disable_commandline_tags=2
disable_fw_kms_setup=1
disable_l2cache=1
disable_overscan=1
display_auto_detect=1
display_default_lcd=-1
display_hdmi_rotate=-1
display_lcd_rotate=-1
dvfs=4
enable_gic=1
force_eeprom_read=1
force_ethernet_phy_address=-1
force_pwm_open=1
framebuffer_depth=16
framebuffer_ignore_alpha=1
framebuffer_swap=1
gpu_freq_min=500
hdmi_enable_4kp60=1
hevc_freq=910
hevc_freq_min=500
ignore_lcd=-1
init_uart_clock=0x2dc6c00
initial_turbo=60
isp_freq=910
isp_freq_min=500
mask_gpu_interrupt1=16418
max_framebuffers=2
over_voltage_avs=0x1e71c
pause_burst_frames=1
pciex4_reset=1
pmic_turbo_threshold=600
program_serial_random=1
total_mem=8192
usb_max_current_enable=1
v3d_freq=960
v3d_freq_min=500
vpred=8847
vpred_max=8847
hdmi_force_cec_address:0=65535
hdmi_force_cec_address:1=65535
device_tree=-
overlay_prefix=overlays/
hdmi_cvt:0=
hdmi_cvt:1=
hdmi_edid_filename:0=
hdmi_edid_filename:1=
hdmi_timings:0=
hdmi_timings:1=

cmdline.txt
-----------

reboot=w coherent_pool=1M 8250.nr_uarts=1 pci=pcie_bus_safe cgroup_disable=memory numa_policy=interleave nvme.max_host_mem_size_mb=32  numa=fake=8 system_heap.max_order=0 iommu_dma_numa_policy=interleave smsc95xx.macaddr=2C:CF:67:1F:2A:80 vc_mem.mem_base=0x3fc00000 vc_mem.mem_size=0x40000000  console=ttyAMA10,115200 console=tty1 root=PARTUUID=74e1369a-02 rootfstype=ext4 fsck.repair=yes rootwait quiet splash plymouth.ignore-serial-consoles cfg80211.ieee80211_regdom=US

pin configuration
-----------------

 0: ip    pu | hi // ID_SDA/GPIO0 = input
 1: ip    pu | hi // ID_SCL/GPIO1 = input
 2: no    pu | -- // GPIO2 = none
 3: no    pu | -- // GPIO3 = none
 4: no    pu | -- // GPIO4 = none
 5: no    pu | -- // GPIO5 = none
 6: no    pu | -- // GPIO6 = none
 7: no    pu | -- // GPIO7 = none
 8: no    pu | -- // GPIO8 = none
 9: no    pd | -- // GPIO9 = none
10: no    pd | -- // GPIO10 = none
11: no    pd | -- // GPIO11 = none
12: no    pd | -- // GPIO12 = none
13: no    pd | -- // GPIO13 = none
14: op dh pd | hi // GPIO14 = output
15: no    pd | -- // GPIO15 = none
16: no    pd | -- // GPIO16 = none
17: op dh pd | hi // GPIO17 = output
18: no    pd | -- // GPIO18 = none
19: no    pd | -- // GPIO19 = none
20: no    pd | -- // GPIO20 = none
21: no    pd | -- // GPIO21 = none
22: no    pd | -- // GPIO22 = none
23: no    pd | -- // GPIO23 = none
24: no    pd | -- // GPIO24 = none
25: no    pd | -- // GPIO25 = none
26: no    pd | -- // GPIO26 = none
27: no    pd | -- // GPIO27 = none
28: no    pd | lo // PCIE_RP1_WAKE/GPIO28 = none
29: no    pu | hi // FAN_TACH/GPIO29 = none
30: no    pu | -- // HOST_SDA/GPIO30 = none
31: no    pu | -- // HOST_SCL/GPIO31 = none
32: op dh pd | hi // ETH_RST_N/GPIO32 = output
33: no    pd | lo // GPIO33 = none
34: op dl pd | lo // CD0_IO0_MICCLK/GPIO34 = output
35: no    pd | lo // CD0_IO0_MICDAT0/GPIO35 = none
36: no    pd | lo // RP1_PCIE_CLKREQ_N/GPIO36 = none
37: no    pd | lo // GPIO37 = none
38: ip    pd | hi // CD0_SDA/GPIO38 = input
39: ip    pd | hi // CD0_SCL/GPIO39 = input
40: ip    pd | hi // CD1_SDA/GPIO40 = input
41: ip    pd | hi // CD1_SCL/GPIO41 = input
42: a2    pd | hi // USB_VBUS_EN/GPIO42 = VBUS_EN1
43: a2    pu | hi // USB_OC_N/GPIO43 = VBUS_OC1
44: op dh pd | hi // RP1_STAT_LED/GPIO44 = output
45: a0    pd | hi // FAN_PWM/GPIO45 = PWM1_CHAN3
46: op dl pd | lo // CD1_IO0_MICCLK/GPIO46 = output
47: no    pd | lo // 2712_WAKE/GPIO47 = none
48: no    pd | lo // CD1_IO1_MICDAT1/GPIO48 = none
49: op dh pd | hi // EN_MAX_USB_CUR/GPIO49 = output
50: no    pd | -- // GPIO50 = none
51: no    pd | -- // GPIO51 = none
52: no    pu | -- // GPIO52 = none
53: no    pu | hi // GPIO53 = none
100: ip    pd | lo // GPIO0 = input
101: a7    pd | hi // 2712_BOOT_CS_N/GPIO1 = VC_SPI0_CE0_N
102: a6    pd | lo // 2712_BOOT_MISO/GPIO2 = VC_SPI0_MISO
103: a5    pd | lo // 2712_BOOT_MOSI/GPIO3 = VC_SPI0_MOSI
104: a6    pd | lo // 2712_BOOT_SCLK/GPIO4 = VC_SPI0_SCLK
105: ip    pd | lo // GPIO5 = input
106: ip    pd | lo // GPIO6 = input
107: ip    pd | lo // GPIO7 = input
108: ip    pd | lo // GPIO8 = input
109: ip    pd | lo // GPIO9 = input
110: ip    pd | lo // GPIO10 = input
111: ip    pd | lo // GPIO11 = input
112: ip    pd | lo // GPIO12 = input
113: ip    pd | lo // GPIO13 = input
114: a1    pd | lo // PCIE_SDA/GPIO14 = SPI_S_MOSI_OR_BSC_S_SDA
115: a1    pd | lo // PCIE_SCL/GPIO15 = SPI_S_SCK_OR_BSC_S_SCL
116: ip    pd | lo // GPIO16 = input
117: ip    pd | lo // GPIO17 = input
118: ip    pd | lo // GPIO18 = input
119: ip    pd | lo // GPIO19 = input
120: ip    pu | hi // PWR_GPIO/GPIO20 = input
121: ip    pd | lo // 2712_G21_FS/GPIO21 = input
122: ip    pd | lo // GPIO22 = input
123: ip    pd | lo // GPIO23 = input
124: a3    pn | lo // BT_RTS/GPIO24 = UART_RTS_0
125: a4    pu | lo // BT_CTS/GPIO25 = UART_CTS_0
126: a4    pn | hi // BT_TXD/GPIO26 = UART_TXD_0
127: a4    pu | hi // BT_RXD/GPIO27 = UART_RXD_0
128: op dh pd | hi // WL_ON/GPIO28 = output
129: op dh pd | hi // BT_ON/GPIO29 = output
130: a4    pn | hi // WIFI_SDIO_CLK/GPIO30 = SD2_CLK
131: a4    pu | hi // WIFI_SDIO_CMD/GPIO31 = SD2_CMD
132: a4    pu | hi // WIFI_SDIO_D0/GPIO32 = SD2_DAT0
133: a3    pu | hi // WIFI_SDIO_D1/GPIO33 = SD2_DAT1
134: a4    pu | hi // WIFI_SDIO_D2/GPIO34 = SD2_DAT2
135: a3    pu | hi // WIFI_SDIO_D3/GPIO35 = SD2_DAT3
200: a6    pd | hi // RP1_SDA/AON_GPIO0 = VC_SDA0
201: a7    pd | hi // RP1_SCL/AON_GPIO1 = VC_SCL0
202: op dh pd | hi // RP1_RUN/AON_GPIO2 = output
203: op dh pd | hi // SD_IOVDD_SEL/AON_GPIO3 = output
204: op dh pd | hi // SD_PWR_ON/AON_GPIO4 = output
205: a6    pu | lo // SD_CDET_N/AON_GPIO5 = SD_CARD_PRES_G
206: ip    pu | hi // SD_FLG_N/AON_GPIO6 = input
207: ip    pd | lo // AON_GPIO7 = input
208: ip    pd | lo // 2712_WAKE/AON_GPIO8 = input
209: op dh pd | hi // 2712_STAT_LED/AON_GPIO9 = output
210: ip    pd | lo // AON_GPIO10 = input
211: ip    pd | lo // AON_GPIO11 = input
212: ip    pd | lo // PMIC_INT/AON_GPIO12 = input
213: a3    pu | hi // UART_TX_FS/AON_GPIO13 = VC_TXD0
214: a3    pu | hi // UART_RX_FS/AON_GPIO14 = VC_RXD0
215: ip    pd | lo // AON_GPIO15 = input
216: ip    pu | hi // AON_GPIO16 = input
232: a1    -- | hi // HDMI0_SCL/AON_SGPIO0 = HDMI_TX0_BSC_SCL
233: a1    -- | hi // HDMI0_SDA/AON_SGPIO1 = HDMI_TX0_BSC_SDA
234: a1    -- | hi // HDMI1_SCL/AON_SGPIO2 = HDMI_TX1_BSC_SCL
235: a1    -- | hi // HDMI1_SDA/AON_SGPIO3 = HDMI_TX1_BSC_SDA
236: a2    -- | hi // PMIC_SCL/AON_SGPIO4 = BSC_M2_SCL
237: a2    -- | hi // PMIC_SDA/AON_SGPIO5 = BSC_M2_SDA

vcdbg log messages
------------------

005375.275: AB: P:N C:1
005375.281: PCI2 init
005375.289: PCI2 reset
005375.294: PCIe scan 00001de4:00000001
005375.301: RP1_CHIP_INFO 20001927
005375.310: RPi: BOOTLOADER release VERSION:086b83e3 DATE: 2026/05/26 TIME: 16:01:25
005375.320: MFG_VER: 1
005375.329: BOOTMODE: 0x06 partition 0 build-ts BUILD_TIMESTAMP=1779807685 serial 016eae90 boardrev d04170 stc 4397619
005375.340: EEPROM ID 0xef4015
005375.348: SFDP v1.5 Param v1.5
005375.356: PCIEx1: PWR 0 DET_WAKE 0
005375.364: usb_pd_init status 3
005375.372: USB_PD CONFIG 0 41
005375.379: XHCI-STOP
005375.388: xHC0 ver: 272 HCS: 03000440 140000f1 07ff000a HCC: 0240fe6d
005375.394: USBSTS 1
005375.403: xHC0 ver: 272 HCS: 03000440 140000f1 07ff000a HCC: 0240fe6d
005375.412: xHC0 ports 3 slots 64 intrs 4
005375.419: XHCI-STOP
005375.428: xHC1 ver: 272 HCS: 03000440 140000f1 07ff000a HCC: 0240fe6d
005375.435: USBSTS 11
005375.443: xHC1 ver: 272 HCS: 03000440 140000f1 07ff000a HCC: 0240fe6d
005375.450: xHC1 ports 3 slots 64 intrs 4
005375.458: SD_OC: 0
005375.464: USB-PD: src-cap PDO object1 0x0a0191f4
005375.471: Current 5000 mA
005375.478: Voltage 5000 mV
005375.486: USB-PD: src-cap PDO object2 0x0002d12c
005375.492: Current 3000 mA
005375.499: Voltage 9000 mV
005375.507: USB-PD: src-cap PDO object3 0x0003c12c
005375.513: Current 3000 mA
005375.520: Voltage 12000 mV
005375.528: USB-PD: src-cap PDO object4 0x0004b12c
005375.537: Current 3000 mA
005375.545: Voltage 15000 mV
005375.552: USB-PD: src-cap PDO object5 0x000640e1
005375.559: Current 2250 mA
005375.565: Voltage 20000 mV
005375.573: USB-PD: src-cap PDO object6 0xc990322d
005375.582: DEV [01:00] 2.00 000000:01 class 239 VID 0c45 PID 0590
005375.593: SD HOST: 200000000 CTL0: 0x00800000 BUS: 400000 Hz actual: 390625 HZ div: 512 (256) status: 0x1fff0000 delay: 276
005375.607: SD HOST: 200000000 CTL0: 0x00800f00 BUS: 400000 Hz actual: 390625 HZ div: 512 (256) status: 0x1fff0000 delay: 276
005375.615: OCR c0ff8000 [206]
005375.624: SD: bus-width: 4 spec: 2 SCR: 0x02358487 0x33333039
005375.635: SD HOST: 200000000 CTL0: 0x00800f04 BUS: 50000000 Hz actual: 50000000 HZ div: 4 (2) status: 0x1fff0000 delay: 2
005375.645: MBR: 0x00004000, 1048576 type: 0x0c
005375.654: MBR: 0x00104000,60067840 type: 0x83
005375.661: MBR: 0x00000000,       0 type: 0x00
005375.670: MBR: 0x00000000,       0 type: 0x00
005375.678: rsc 32 fat-sectors 8066 root dir cluster 2 sectors 0 entries 0
005375.687: FAT32 clusters 1032412
005375.696: [sdcard] autoboot.txt not found
005375.706: Select partition rsts 0 C(boot_partition) 0 EEPROM config 0 result 1
005375.714: rsc 32 fat-sectors 8066 root dir cluster 2 sectors 0 entries 0
005375.721: FAT32 clusters 1032408
005375.728: [sdcard] pieeprom.upd not found
005375.734: dt-match: compatible: raspberrypi,5-model-b match: brcm,bcm2712
005375.745: dt-match: compatible: brcm,bcm2712 match: brcm,bcm2712
005375.776: *** Restart logging
005384.802: board: boardrev d04170 otp d04170
005398.312: Initial voltage 800000 temp 38379
005598.889: avs_2712: AVS pred 8847 884700 temp 39478
005602.496: vpred 884 mV +0
005606.702: over-voltage idle: 0 avs: 124700 delta: 0 (0x00000000)
006239.660: FB framebuffer_swap 1
006254.003: Select resolution HDMI0/2 hotplug 0 max_mode 2
006258.040: Select resolution HDMI1/2 hotplug 0 max_mode 2
007359.663: initramfs (initramfs_2712) loaded to 0x2da45000 (size 0x15ba722)
007365.317: dtb_file 'bcm2712-rpi-5-b.dtb'
007450.713: dtparam: audio=on
007457.437: Unknown dtparam 'audio' - ignored
007515.808: Loaded overlay 'vc4-kms-v3d-pi5'
007593.729: Loaded overlay 'nospi10'
007641.197: Read command line from file 'cmdline.txt':
007647.708: 'console=serial0,115200 console=tty1 root=PARTUUID=74e1369a-02 rootfstype=ext4 fsck.repair=yes rootwait quiet splash plymouth.ignore-serial-consoles cfg80211.ieee80211_regdom=US'
007766.118: RPM 145, max RPM 295
009057.522: Device tree loaded to 0x2da31600 (size 0x139db)
009124.737: Starting OS 9124 ms
009130.261: 00000040: -> 00000480
009132.112: 00000030: -> 00100080
009136.825: 00000034: -> 00100080
009141.538: 00000038: -> 00100080
009146.250: 0000003c: -> 00100080
009258.783: sdram: sdram refresh 2081->4162 (2)
069201.329: initial_turbo of 60 deactivated

dmesg log
---------

[    0.000000] Booting Linux on physical CPU 0x0000000000 [0x414fd0b1]
[    0.000000] Linux version 6.18.34+rpt-rpi-2712 (serge@raspberrypi.com) (aarch64-linux-gnu-gcc-14 (Debian 14.2.0-19) 14.2.0, GNU ld (GNU Binutils for Debian) 2.44) #1 SMP PREEMPT Debian 1:6.18.34-1+rpt1 (2026-06-09)
[    0.000000] KASLR enabled
[    0.000000] random: crng init done
[    0.000000] Machine model: Raspberry Pi 5 Model B Rev 1.0
[    0.000000] efi: UEFI not found.
[    0.000000] Reserved memory: created CMA memory pool at 0x000000003a000000, size 64 MiB
[    0.000000] OF: reserved mem: initialized node linux,cma, compatible id shared-dma-pool
[    0.000000] OF: reserved mem: 0x000000003a000000..0x000000003dffffff (65536 KiB) map reusable linux,cma
[    0.000000] OF: reserved mem: 0x0000000000000000..0x000000000007ffff (512 KiB) nomap non-reusable atf@0
[    0.000000] OF: reserved mem: 0x000000003fd235e0..0x000000003fd23617 (0 KiB) nomap non-reusable nvram@0
[    0.000000] NUMA: Faking a node at [mem 0x0000000000000000-0x00000001ffffffff]
[    0.000000] Faking node 0 at [mem 0x0000000000000000-0x000000003fffffff] (1024MB)
[    0.000000] Faking node 1 at [mem 0x0000000040000000-0x000000007fffffff] (1024MB)
[    0.000000] Faking node 2 at [mem 0x0000000080000000-0x00000000bfffffff] (1024MB)
[    0.000000] Faking node 3 at [mem 0x00000000c0000000-0x00000000ffffffff] (1024MB)
[    0.000000] Faking node 4 at [mem 0x0000000100000000-0x000000013fffffff] (1024MB)
[    0.000000] Faking node 5 at [mem 0x0000000140000000-0x000000017fffffff] (1024MB)
[    0.000000] Faking node 6 at [mem 0x0000000180000000-0x00000001bfffffff] (1024MB)
[    0.000000] Faking node 7 at [mem 0x00000001c0000000-0x00000001ffffffff] (1024MB)
[    0.000000] NODE_DATA(0) allocated [mem 0x3fbfd180-0x3fbfffff]
[    0.000000] NODE_DATA(1) allocated [mem 0x7fffd180-0x7fffffff]
[    0.000000] NODE_DATA(2) allocated [mem 0xbfffd180-0xbfffffff]
[    0.000000] NODE_DATA(3) allocated [mem 0xffffd180-0xffffffff]
[    0.000000] NODE_DATA(4) allocated [mem 0x13fffd180-0x13fffffff]
[    0.000000] NODE_DATA(5) allocated [mem 0x17fffd180-0x17fffffff]
[    0.000000] NODE_DATA(6) allocated [mem 0x1bfffd180-0x1bfffffff]
[    0.000000] NODE_DATA(7) allocated [mem 0x1ffb9c4c0-0x1ffb9f33f]
[    0.000000] Zone ranges:
[    0.000000]   DMA      [mem 0x0000000000000000-0x00000000ffffffff]
[    0.000000]   DMA32    empty
[    0.000000]   Normal   [mem 0x0000000100000000-0x00000001ffffffff]
[    0.000000] Movable zone start for each node
[    0.000000] Early memory node ranges
[    0.000000]   node   0: [mem 0x0000000000000000-0x000000000007ffff]
[    0.000000]   node   0: [mem 0x0000000000080000-0x000000003fbfffff]
[    0.000000]   node   1: [mem 0x0000000040000000-0x000000007fffffff]
[    0.000000]   node   2: [mem 0x0000000080000000-0x00000000bfffffff]
[    0.000000]   node   3: [mem 0x00000000c0000000-0x00000000ffffffff]
[    0.000000]   node   4: [mem 0x0000000100000000-0x000000013fffffff]
[    0.000000]   node   5: [mem 0x0000000140000000-0x000000017fffffff]
[    0.000000]   node   6: [mem 0x0000000180000000-0x00000001bfffffff]
[    0.000000]   node   7: [mem 0x00000001c0000000-0x00000001ffffffff]
[    0.000000] Initmem setup node 0 [mem 0x0000000000000000-0x000000003fbfffff]
[    0.000000] Initmem setup node 1 [mem 0x0000000040000000-0x000000007fffffff]
[    0.000000] Initmem setup node 2 [mem 0x0000000080000000-0x00000000bfffffff]
[    0.000000] Initmem setup node 3 [mem 0x00000000c0000000-0x00000000ffffffff]
[    0.000000] Initmem setup node 4 [mem 0x0000000100000000-0x000000013fffffff]
[    0.000000] Initmem setup node 5 [mem 0x0000000140000000-0x000000017fffffff]
[    0.000000] Initmem setup node 6 [mem 0x0000000180000000-0x00000001bfffffff]
[    0.000000] Initmem setup node 7 [mem 0x00000001c0000000-0x00000001ffffffff]
[    0.000000] On node 1, zone DMA: 256 pages in unavailable ranges
[    0.000000] psci: probing for conduit method from DT.
[    0.000000] psci: PSCIv1.1 detected in firmware.
[    0.000000] psci: Using standard PSCI v0.2 function IDs
[    0.000000] psci: MIGRATE_INFO_TYPE not supported.
[    0.000000] psci: SMC Calling Convention v1.2
[    0.000000] percpu: Embedded 9 pages/cpu s95512 r8192 d43752 u147456
[    0.000000] pcpu-alloc: s95512 r8192 d43752 u147456 alloc=9*16384
[    0.000000] pcpu-alloc: [0] 0 [0] 1 [0] 2 [0] 3 
[    0.000000] Detected PIPT I-cache on CPU0
[    0.000000] CPU features: detected: Virtualization Host Extensions
[    0.000000] CPU features: detected: Spectre-v4
[    0.000000] CPU features: detected: Spectre-BHB
[    0.000000] CPU features: kernel page table isolation forced ON by KASLR
[    0.000000] CPU features: detected: Kernel page table isolation (KPTI)
[    0.000000] CPU features: detected: SSBS not fully self-synchronizing
[    0.000000] alternatives: applying boot alternatives
[    0.000000] Kernel command line: reboot=w coherent_pool=1M 8250.nr_uarts=1 pci=pcie_bus_safe cgroup_disable=memory numa_policy=interleave nvme.max_host_mem_size_mb=32  numa=fake=8 system_heap.max_order=0 iommu_dma_numa_policy=interleave smsc95xx.macaddr=m.m.m.m vc_mem.mem_base=0x3fc00000 vc_mem.mem_size=0x40000000  console=ttyAMA10,115200 console=tty1 root=PARTUUID=74e1369a-02 rootfstype=ext4 fsck.repair=yes rootwait quiet splash plymouth.ignore-serial-consoles cfg80211.ieee80211_regdom=US
[    0.000000] cgroup: Disabling memory control group subsystem
[    0.000000] mempolicy: NUMA default policy overridden to 'interleave:0-7'
[    0.000000] DMA IOMMU NUMA default policy overridden to 'interleave:0-7'
[    0.000000] Unknown kernel command line parameters "splash", will be passed to user space.
[    0.000000] printk: log buffer data + meta data: 131072 + 458752 = 589824 bytes
[    0.000000] software IO TLB: area num 4.
[    0.000000] software IO TLB: mapped [mem 0x00000000fbffc000-0x00000000ffffc000] (64MB)
[    0.000000] Fallback order for Node 0: 0 1 2 3 4 5 6 7 
[    0.000000] Fallback order for Node 1: 1 2 3 4 5 6 7 0 
[    0.000000] Fallback order for Node 2: 2 3 4 5 6 7 0 1 
[    0.000000] Fallback order for Node 3: 3 4 5 6 7 0 1 2 
[    0.000000] Fallback order for Node 4: 4 5 6 7 0 1 2 3 
[    0.000000] Fallback order for Node 5: 5 6 7 0 1 2 3 4 
[    0.000000] Fallback order for Node 6: 6 7 0 1 2 3 4 5 
[    0.000000] Fallback order for Node 7: 7 0 1 2 3 4 5 6 
[    0.000000] Built 8 zonelists, mobility grouping on.  Total pages: 524032
[    0.000000] Policy zone: Normal
[    0.000000] mem auto-init: stack:all(zero), heap alloc:off, heap free:off
[    0.000000] SLUB: HWalign=64, Order=0-3, MinObjects=0, CPUs=4, Nodes=8
[    0.000000] ftrace: allocating 46711 entries in 46 pages
[    0.000000] ftrace: allocated 46 pages with 4 groups
[    0.000000] rcu: Preemptible hierarchical RCU implementation.
[    0.000000] rcu: 	RCU event tracing is enabled.
[    0.000000] 	Trampoline variant of Tasks RCU enabled.
[    0.000000] 	Rude variant of Tasks RCU enabled.
[    0.000000] 	Tracing variant of Tasks RCU enabled.
[    0.000000] rcu: RCU calculated value of scheduler-enlistment delay is 25 jiffies.
[    0.000000] RCU Tasks: Setting shift to 2 and lim to 1 rcu_task_cb_adjust=1 rcu_task_cpu_ids=4.
[    0.000000] RCU Tasks Rude: Setting shift to 2 and lim to 1 rcu_task_cb_adjust=1 rcu_task_cpu_ids=4.
[    0.000000] RCU Tasks Trace: Setting shift to 2 and lim to 1 rcu_task_cb_adjust=1 rcu_task_cpu_ids=4.
[    0.000000] NR_IRQS: 64, nr_irqs: 64, preallocated irqs: 0
[    0.000000] Root IRQ handler: gic_handle_irq
[    0.000000] GIC: Using split EOI/Deactivate mode
[    0.000000] rcu: srcu_init: Setting srcu_struct sizes based on contention.
[    0.000000] arch_timer: cp15 timer running at 54.00MHz (phys).
[    0.000000] clocksource: arch_sys_counter: mask: 0xffffffffffffff max_cycles: 0xc743ce346, max_idle_ns: 440795203123 ns
[    0.000000] sched_clock: 56 bits at 54MHz, resolution 18ns, wraps every 4398046511102ns
[    0.000088] Console: colour dummy device 80x25
[    0.000092] printk: legacy console [tty1] enabled
[    0.000150] Calibrating delay loop (skipped), value calculated using timer frequency.. 108.00 BogoMIPS (lpj=216000)
[    0.000153] pid_max: default: 32768 minimum: 301
[    0.000243] LSM: initializing lsm=capability
[    0.001696] Dentry cache hash table entries: 1048576 (order: 9, 8388608 bytes, vmalloc hugepage)
[    0.002397] Inode-cache hash table entries: 524288 (order: 8, 4194304 bytes, vmalloc hugepage)
[    0.002436] Mount-cache hash table entries: 16384 (order: 3, 131072 bytes, vmalloc)
[    0.002452] Mountpoint-cache hash table entries: 16384 (order: 3, 131072 bytes, vmalloc)
[    0.003095] rcu: Hierarchical SRCU implementation.
[    0.003099] rcu: 	Max phase no-delay instances is 1000.
[    0.003139] Timer migration: 1 hierarchy levels; 8 children per group; 0 crossnode level
[    0.003456] EFI services will not be available.
[    0.003518] smp: Bringing up secondary CPUs ...
[    0.003694] Detected PIPT I-cache on CPU1
[    0.003746] CPU1: Booted secondary processor 0x0000000100 [0x414fd0b1]
[    0.003957] Detected PIPT I-cache on CPU2
[    0.004001] CPU2: Booted secondary processor 0x0000000200 [0x414fd0b1]
[    0.004197] Detected PIPT I-cache on CPU3
[    0.004230] CPU3: Booted secondary processor 0x0000000300 [0x414fd0b1]
[    0.004256] smp: Brought up 8 nodes, 4 CPUs
[    0.004260] SMP: Total of 4 processors activated.
[    0.004261] CPU: All CPU(s) started at EL2
[    0.004264] CPU features: detected: 32-bit EL0 Support
[    0.004266] CPU features: detected: Data cache clean to the PoU not required for I/D coherence
[    0.004267] CPU features: detected: Common not Private translations
[    0.004268] CPU features: detected: CRC32 instructions
[    0.004271] CPU features: detected: RCpc load-acquire (LDAPR)
[    0.004273] CPU features: detected: LSE atomic instructions
[    0.004274] CPU features: detected: Privileged Access Never
[    0.004275] CPU features: detected: PMUv3
[    0.004276] CPU features: detected: RAS Extension Support
[    0.004278] CPU features: detected: Speculative Store Bypassing Safe (SSBS)
[    0.004300] alternatives: applying system-wide alternatives
[    0.005829] CPU features: detected: Hardware dirty bit management on CPU0-3
[    0.005931] Memory: 8143280K/8384512K available (15040K kernel code, 2466K rwdata, 5216K rodata, 2240K init, 563K bss, 153104K reserved, 65536K cma-reserved)
[    0.006103] devtmpfs: initialized
[    0.008025] Enabled cp15_barrier support
[    0.008030] Enabled setend support
[    0.008145] clocksource: jiffies: mask: 0xffffffff max_cycles: 0xffffffff, max_idle_ns: 7645041785100000 ns
[    0.008158] posixtimers hash table entries: 2048 (order: 1, 32768 bytes, vmalloc)
[    0.008179] futex hash table entries: 128 (8192 bytes on 8 NUMA nodes, total 64 KiB, linear).
[    0.008269] 2G module region forced by RANDOMIZE_MODULE_REGION_FULL
[    0.008271] 0 pages in range for non-PLT usage
[    0.008272] 129452 pages in range for PLT usage
[    0.008350] pinctrl core: initialized pinctrl subsystem
[    0.008469] DMI not present or invalid.
[    0.011663] NET: Registered PF_NETLINK/PF_ROUTE protocol family
[    0.011997] DMA: preallocated 1024 KiB GFP_KERNEL pool for atomic allocations
[    0.012028] DMA: preallocated 1024 KiB GFP_KERNEL|GFP_DMA pool for atomic allocations
[    0.012059] DMA: preallocated 1024 KiB GFP_KERNEL|GFP_DMA32 pool for atomic allocations
[    0.012069] audit: initializing netlink subsys (disabled)
[    0.012114] audit: type=2000 audit(0.012:1): state=initialized audit_enabled=0 res=1
[    0.012205] thermal_sys: Registered thermal governor 'step_wise'
[    0.012214] cpuidle: using governor menu
[    0.012268] hw-breakpoint: found 6 breakpoint and 4 watchpoint registers.
[    0.012286] ASID allocator initialised with 32768 entries
[    0.012483] Serial: AMBA PL011 UART driver
[    0.013166] /soc@107c000000/interrupt-controller@7fff9000: Fixed dependency cycle(s) with /soc@107c000000/interrupt-controller@7fff9000
[    0.013325] bcm2835-mbox 107c013880.mailbox: mailbox enabled
[    0.013444] 107d001000.serial: ttyAMA10 at MMIO 0x107d001000 (irq = 16, base_baud = 0) is a PL011 rev3
[    0.013477] printk: console [ttyAMA10] enabled
[    0.020038] raspberrypi-firmware soc@107c000000:firmware: Attached to firmware from 2026-05-26T15:01:25, variant start_cd
[    0.024037] raspberrypi-firmware soc@107c000000:firmware: Firmware hash is 086b83e300000000000000000000000000000000
[    0.030563] bcm2835-dma 1000010000.dma: DMA legacy API manager, dmachans=0x1
[    0.030831] iommu: Default domain type: Translated
[    0.030836] iommu: DMA domain TLB invalidation policy: strict mode
[    0.035823] SCSI subsystem initialized
[    0.035860] usbcore: registered new interface driver usbfs
[    0.035867] usbcore: registered new interface driver hub
[    0.035874] usbcore: registered new device driver usb
[    0.035941] pps_core: LinuxPPS API ver. 1 registered
[    0.035943] pps_core: Software ver. 5.3.6 - Copyright 2005-2007 Rodolfo Giometti <giometti@linux.it>
[    0.035946] PTP clock support registered
[    0.036219] vgaarb: loaded
[    0.036296] clocksource: Switched to clocksource arch_sys_counter
[    0.221889] VFS: Disk quotas dquot_6.6.0
[    0.221902] VFS: Dquot-cache hash table entries: 2048 (order 0, 16384 bytes)
[    0.223039] NET: Registered PF_INET protocol family
[    0.223209] IP idents hash table entries: 131072 (order: 6, 1048576 bytes, vmalloc)
[    0.224871] tcp_listen_portaddr_hash hash table entries: 4096 (order: 2, 65536 bytes, vmalloc)
[    0.224901] Table-perturb hash table entries: 65536 (order: 4, 262144 bytes, vmalloc)
[    0.224920] TCP established hash table entries: 65536 (order: 5, 524288 bytes, vmalloc)
[    0.225108] TCP bind hash table entries: 65536 (order: 7, 2097152 bytes, vmalloc hugepage)
[    0.226066] TCP: Hash tables configured (established 65536 bind 65536)
[    0.226231] MPTCP token hash table entries: 8192 (order: 4, 196608 bytes, vmalloc)
[    0.226281] UDP hash table entries: 4096 (order: 4, 262144 bytes, vmalloc)
[    0.226415] UDP-Lite hash table entries: 4096 (order: 4, 262144 bytes, vmalloc)
[    0.226597] NET: Registered PF_UNIX/PF_LOCAL protocol family
[    0.226853] RPC: Registered named UNIX socket transport module.
[    0.226857] RPC: Registered udp transport module.
[    0.226858] RPC: Registered tcp transport module.
[    0.226860] RPC: Registered tcp-with-tls transport module.
[    0.226861] RPC: Registered tcp NFSv4.1 backchannel transport module.
[    0.226866] PCI: CLS 0 bytes, default 64
[    0.226937] Trying to unpack rootfs image as initramfs...
[    0.233362] kvm [1]: nv: 568 coarse grained trap handlers
[    0.233487] kvm [1]: IPA Size Limit: 40 bits
[    0.233500] kvm [1]: GICV region size/alignment is unsafe, using trapping (reduced performance)
[    0.233528] kvm [1]: vgic interrupt IRQ9
[    0.233545] kvm [1]: VHE mode initialized successfully
[    0.234035] Initialise system trusted keyrings
[    0.234286] workingset: timestamp_bits=42 max_order=19 bucket_order=0
[    0.234579] NFS: Registering the id_resolver key type
[    0.234586] Key type id_resolver registered
[    0.234588] Key type id_legacy registered
[    0.234600] nfs4filelayout_init: NFSv4 File Layout Driver Registering...
[    0.234603] nfs4flexfilelayout_init: NFSv4 Flexfile Layout Driver Registering...
[    0.234803] Key type asymmetric registered
[    0.234808] Asymmetric key parser 'x509' registered
[    0.234827] Block layer SCSI generic (bsg) driver version 0.4 loaded (major 246)
[    0.234857] io scheduler mq-deadline registered
[    0.234860] io scheduler kyber registered
[    0.234872] io scheduler bfq registered
[    0.235191] irq_brcmstb_l2: registered L2 intc (/soc@107c000000/interrupt-controller@7d510600, parent irq: 27)
[    0.235228] irq_brcmstb_l2: registered L2 intc (/soc@107c000000/interrupt-controller@7c502000, parent irq: 28)
[    0.235258] irq_brcmstb_l2: registered L2 intc (/soc@107c000000/interrupt-controller@7d508380, parent irq: 29)
[    0.235290] irq_brcmstb_l2: registered L2 intc (/soc@107c000000/interrupt-controller@7d508400, parent irq: 30)
[    0.235324] irq_brcmstb_l2: registered L2 intc (/soc@107c000000/intc@7d503000, parent irq: 31)
[    0.236354] ledtrig-cpu: registered to indicate activity on CPUs
[    0.385515] Freeing initrd memory: 22224K
[    0.434162] Serial: 8250/16550 driver, 1 ports, IRQ sharing enabled
[    0.434561] 107d50c000.serial: ttyS0 at MMIO 0x107d50c000 (irq = 33, base_baud = 6000000) is a Broadcom BCM7271 UART
[    0.434605] serial serial0: tty port ttyS0 registered
[    0.434865] iproc-rng200 107d208000.rng: hwrng registered
[    0.434894] vc-mem: phys_addr:0x00000000 mem_base=0x3fc00000 mem_size:0x40000000(1024 MiB)
[    0.435125] bcm2712-iommu-cache 1000005b00.iommuc: bcm2712_iommu_cache_probe
[    0.436511] brd: module loaded
[    0.437392] loop: module loaded
[    0.437617] bcm2835-power bcm2835-power: Broadcom BCM2835 power domains driver
[    0.437738] Loading iSCSI transport class v2.0-870.
[    0.438384] usbcore: registered new interface driver lan78xx
[    0.438395] usbcore: registered new interface driver smsc95xx
[    0.438438] dwc_otg: version 3.00a 10-AUG-2012 (platform bus)
[    0.438453] dwc_otg: FIQ enabled
[    0.438455] dwc_otg: NAK holdoff enabled
[    0.438457] dwc_otg: FIQ split-transaction FSM enabled
[    0.438460] Module dwc_common_port init
[    0.438647] usbcore: registered new interface driver uas
[    0.438656] usbcore: registered new interface driver usb-storage
[    0.438720] mousedev: PS/2 mouse device common for all mice
[    0.445959] rpi-rtc soc@107c000000:rpi_rtc: registered as rtc0
[    0.447297] rpi-rtc soc@107c000000:rpi_rtc: setting system clock to 1970-01-01T00:00:09 UTC (9)
[    0.447588] bcm2835-wdt bcm2835-wdt: Poweroff handler already present!
[    0.447591] bcm2835-wdt bcm2835-wdt: Broadcom BCM2835 watchdog timer
[    0.449496] sdhci: Secure Digital Host Controller Interface driver
[    0.449499] sdhci: Copyright(c) Pierre Ossman
[    0.449526] sdhci-pltfm: SDHCI platform and OF driver helper
[    0.449586] SMCCC: SOC_ID: ARCH_SOC_ID not implemented, skipping ....
[    0.449613] hid: raw HID events driver (C) Jiri Kosina
[    0.449633] usbcore: registered new interface driver usbhid
[    0.449636] usbhid: USB HID core driver
[    0.449905] hw perfevents: enabled with armv8_cortex_a76 PMU driver, 7 (0,8000003f) counters available
[    0.450131] NET: Registered PF_PACKET protocol family
[    0.450158] Key type dns_resolver registered
[    0.453813] registered taskstats version 1
[    0.453876] Loading compiled-in X.509 certificates
[    0.455515] Demotion targets for Node 0: null
[    0.455518] Demotion targets for Node 1: null
[    0.455519] Demotion targets for Node 2: null
[    0.455521] Demotion targets for Node 3: null
[    0.455523] Demotion targets for Node 4: null
[    0.455524] Demotion targets for Node 5: null
[    0.455526] Demotion targets for Node 6: null
[    0.455528] Demotion targets for Node 7: null
[    0.455599] Key type .fscrypt registered
[    0.455601] Key type fscrypt-provisioning registered
[    0.456339] brcm-pcie 1000120000.pcie: host bridge /axi/pcie@1000120000 ranges:
[    0.456352] brcm-pcie 1000120000.pcie:      MEM 0x1f00000000..0x1ffffffffb -> 0x0000000000
[    0.456357] brcm-pcie 1000120000.pcie:      MEM 0x1c00000000..0x1effffffff -> 0x0400000000
[    0.456365] brcm-pcie 1000120000.pcie:   IB MEM 0x1f00000000..0x1f003fffff -> 0x0000000000
[    0.456372] brcm-pcie 1000120000.pcie:   IB MEM 0x0000000000..0x0fffffffff -> 0x1000000000
[    0.456377] brcm-pcie 1000120000.pcie:   IB MEM 0x1000130000..0x1000130fff -> 0xfffffff000
[    0.457711] brcm-pcie 1000120000.pcie: PCI host bridge to bus 0002:00
[    0.457716] pci_bus 0002:00: root bus resource [bus 00-ff]
[    0.457719] pci_bus 0002:00: root bus resource [mem 0x1f00000000-0x1ffffffffb] (bus address [0x00000000-0xfffffffb])
[    0.457722] pci_bus 0002:00: root bus resource [mem 0x1c00000000-0x1effffffff pref] (bus address [0x400000000-0x6ffffffff])
[    0.457737] pci 0002:00:00.0: [14e4:2712] type 01 class 0x060400 PCIe Root Port
[    0.457744] pci 0002:00:00.0: PCI bridge to [bus 00]
[    0.457748] pci 0002:00:00.0:   bridge window [mem 0x1f80000000-0x1fbfffffff]
[    0.457764] pci 0002:00:00.0: PME# supported from D0 D3hot
[    0.458304] pci 0002:00:00.0: bridge configuration invalid ([bus 00-00]), reconfiguring
[    0.560302] brcm-pcie 1000120000.pcie: clkreq-mode set to default
[    0.560306] brcm-pcie 1000120000.pcie: link up, 5.0 GT/s PCIe x4 (!SSC)
[    0.560328] pci 0002:01:00.0: [1de4:0001] type 00 class 0x020000 PCIe Endpoint
[    0.560366] pci 0002:01:00.0: BAR 0 [mem 0xffffc000-0xffffffff]
[    0.560371] pci 0002:01:00.0: BAR 1 [mem 0xffc00000-0xffffffff]
[    0.560374] pci 0002:01:00.0: BAR 2 [mem 0xffff0000-0xffffffff]
[    0.560425] pci 0002:01:00.0: supports D1
[    0.560427] pci 0002:01:00.0: PME# supported from D0 D1 D3hot D3cold
[    0.568299] pci 0002:01:00.0: ASPM: default states L1
[    0.568307] pci_bus 0002:01: busn_res: [bus 01-ff] end is updated to 01
[    0.568316] pci 0002:00:00.0: bridge window [mem 0x1f00000000-0x1f004fffff]: assigned
[    0.568320] pci 0002:01:00.0: BAR 1 [mem 0x1f00000000-0x1f003fffff]: assigned
[    0.568324] pci 0002:01:00.0: BAR 2 [mem 0x1f00400000-0x1f0040ffff]: assigned
[    0.568329] pci 0002:01:00.0: BAR 0 [mem 0x1f00410000-0x1f00413fff]: assigned
[    0.568334] pci 0002:00:00.0: PCI bridge to [bus 01]
[    0.568337] pci 0002:00:00.0:   bridge window [mem 0x1f00000000-0x1f004fffff]
[    0.568340] pci_bus 0002:00: resource 4 [mem 0x1f00000000-0x1ffffffffb]
[    0.568343] pci_bus 0002:00: resource 5 [mem 0x1c00000000-0x1effffffff pref]
[    0.568345] pci_bus 0002:01: resource 1 [mem 0x1f00000000-0x1f004fffff]
[    0.568349] pci 0002:00:00.0: Max Payload Size set to  256/ 512 (was  128), Max Read Rq  512
[    0.568357] pci 0002:01:00.0: Max Payload Size set to  256/ 256 (was  128), Max Read Rq  512
[    0.568450] pcieport 0002:00:00.0: enabling device (0000 -> 0002)
[    0.568480] pcieport 0002:00:00.0: PME: Signaling with IRQ 38
[    0.568525] pcieport 0002:00:00.0: AER: enabled with IRQ 38
[    0.568636] rp1 0002:01:00.0: bar0 len 0x4000, start 0x1f00410000, end 0x1f00413fff, flags, 0x40200
[    0.568641] rp1 0002:01:00.0: bar1 len 0x400000, start 0x1f00000000, end 0x1f003fffff, flags, 0x40200
[    0.568652] rp1 0002:01:00.0: enabling device (0000 -> 0002)
[    0.569272] rp1 0002:01:00.0: chip_id 0x20001927
[    0.571673] bcm2712-iommu 1000005100.iommu: IOVA aperture 0xa00000000..0xb00000000 including DMA offset 0x0
[    0.571693] bcm2712-iommu 1000005100.iommu: bcm2712_iommu_init: DEBUG_INFO = 0x20804774
[    0.571803] platform 1000800000.codec: bcm2712_iommu_of_xlate: MMU 1000005100.iommu
[    0.571807] platform 1000800000.codec: bcm2712_iommu_probe_device: MMU 1000005100.iommu
[    0.571811] platform 1000800000.codec: bcm2712_iommu_device_group: MMU 1000005100.iommu
[    0.571815] platform 1000800000.codec: Adding to iommu group 0
[    0.571829] platform 1000880000.pisp_be: bcm2712_iommu_of_xlate: MMU 1000005100.iommu
[    0.571832] platform 1000880000.pisp_be: bcm2712_iommu_probe_device: MMU 1000005100.iommu
[    0.571836] platform 1000880000.pisp_be: bcm2712_iommu_device_group: MMU 1000005100.iommu
[    0.571839] platform 1000880000.pisp_be: Adding to iommu group 0
[    0.571896] platform 1000800000.codec: bcm2712_iommu_attach_dev: MMU 1000005100.iommu
[    0.571898] platform 1000880000.pisp_be: bcm2712_iommu_attach_dev: MMU 1000005100.iommu
[    0.571937] bcm2712-iommu 1000005200.iommu: IOVA aperture 0xa00000000..0xa80000000 including DMA offset 0x0
[    0.571952] bcm2712-iommu 1000005200.iommu: bcm2712_iommu_init: DEBUG_INFO = 0x20804774
[    0.571997] platform axi:gpu: bcm2712_iommu_of_xlate: MMU 1000005200.iommu
[    0.572000] platform axi:gpu: bcm2712_iommu_probe_device: MMU 1000005200.iommu
[    0.572004] platform axi:gpu: bcm2712_iommu_device_group: MMU 1000005200.iommu
[    0.572008] platform axi:gpu: Adding to iommu group 1
[    0.572020] platform 107c580000.hvs: bcm2712_iommu_of_xlate: MMU 1000005200.iommu
[    0.572022] platform 107c580000.hvs: bcm2712_iommu_probe_device: MMU 1000005200.iommu
[    0.572026] platform 107c580000.hvs: bcm2712_iommu_device_group: MMU 1000005200.iommu
[    0.572030] platform 107c580000.hvs: Adding to iommu group 1
[    0.572057] platform axi:gpu: bcm2712_iommu_attach_dev: MMU 1000005200.iommu
[    0.572059] platform 107c580000.hvs: bcm2712_iommu_attach_dev: MMU 1000005200.iommu
[    0.572092] bcm2712-iommu 1000005280.iommu: IOVA aperture 0x1a00000000..0x1a80000000 including DMA offset 0x1000000000
[    0.572107] bcm2712-iommu 1000005280.iommu: bcm2712_iommu_init: DEBUG_INFO = 0x20804774
[    0.572424] sdhci-brcmstb 1000fff000.mmc: Got CD GPIO
[    0.572536] mmc1: CQHCI version 5.10
[    0.572564] mmc0: CQHCI version 5.10
[    0.587560] macb 1f00100000.ethernet eth0: Cadence GEM rev 0x00070109 at 0x1f00100000 irq 106 (m.m.m.m)
[    0.587755] dw_axi_dmac_platform 1f00188000.dma: DesignWare AXI DMA Controller, 8 channels
[    0.587951] xhci-hcd xhci-hcd.0: xHCI Host Controller
[    0.587958] xhci-hcd xhci-hcd.0: new USB bus registered, assigned bus number 1
[    0.588391] xhci-hcd xhci-hcd.0: hcc params 0x0240fe6d hci version 0x110 quirks 0x0000808000000810
[    0.588401] xhci-hcd xhci-hcd.0: irq 131, io mem 0x1f00200000
[    0.588460] xhci-hcd xhci-hcd.0: xHCI Host Controller
[    0.588463] xhci-hcd xhci-hcd.0: new USB bus registered, assigned bus number 2
[    0.588466] xhci-hcd xhci-hcd.0: Host supports USB 3.0 SuperSpeed
[    0.588503] usb usb1: New USB device found, idVendor=1d6b, idProduct=0002, bcdDevice= 6.18
[    0.588506] usb usb1: New USB device strings: Mfr=3, Product=2, SerialNumber=1
[    0.588509] usb usb1: Product: xHCI Host Controller
[    0.588511] usb usb1: Manufacturer: Linux 6.18.34+rpt-rpi-2712 xhci-hcd
[    0.588513] usb usb1: SerialNumber: xhci-hcd.0
[    0.588614] hub 1-0:1.0: USB hub found
[    0.588626] hub 1-0:1.0: 2 ports detected
[    0.588724] usb usb2: New USB device found, idVendor=1d6b, idProduct=0003, bcdDevice= 6.18
[    0.588727] usb usb2: New USB device strings: Mfr=3, Product=2, SerialNumber=1
[    0.588730] usb usb2: Product: xHCI Host Controller
[    0.588732] usb usb2: Manufacturer: Linux 6.18.34+rpt-rpi-2712 xhci-hcd
[    0.588734] usb usb2: SerialNumber: xhci-hcd.0
[    0.588791] hub 2-0:1.0: USB hub found
[    0.588803] hub 2-0:1.0: 1 port detected
[    0.588997] xhci-hcd xhci-hcd.1: xHCI Host Controller
[    0.589002] xhci-hcd xhci-hcd.1: new USB bus registered, assigned bus number 3
[    0.589431] xhci-hcd xhci-hcd.1: hcc params 0x0240fe6d hci version 0x110 quirks 0x0000808000000810
[    0.589440] xhci-hcd xhci-hcd.1: irq 136, io mem 0x1f00300000
[    0.589495] xhci-hcd xhci-hcd.1: xHCI Host Controller
[    0.589498] xhci-hcd xhci-hcd.1: new USB bus registered, assigned bus number 4
[    0.589501] xhci-hcd xhci-hcd.1: Host supports USB 3.0 SuperSpeed
[    0.589526] usb usb3: New USB device found, idVendor=1d6b, idProduct=0002, bcdDevice= 6.18
[    0.589529] usb usb3: New USB device strings: Mfr=3, Product=2, SerialNumber=1
[    0.589532] usb usb3: Product: xHCI Host Controller
[    0.589534] usb usb3: Manufacturer: Linux 6.18.34+rpt-rpi-2712 xhci-hcd
[    0.589536] usb usb3: SerialNumber: xhci-hcd.1
[    0.589599] hub 3-0:1.0: USB hub found
[    0.589611] hub 3-0:1.0: 2 ports detected
[    0.589690] usb usb4: New USB device found, idVendor=1d6b, idProduct=0003, bcdDevice= 6.18
[    0.589693] usb usb4: New USB device strings: Mfr=3, Product=2, SerialNumber=1
[    0.589696] usb usb4: Product: xHCI Host Controller
[    0.589697] usb usb4: Manufacturer: Linux 6.18.34+rpt-rpi-2712 xhci-hcd
[    0.589699] usb usb4: SerialNumber: xhci-hcd.1
[    0.589757] hub 4-0:1.0: USB hub found
[    0.589767] hub 4-0:1.0: 1 port detected
[    0.590133] of_cfs_init
[    0.590162] of_cfs_init: OK
[    0.590230] clk: Disabling unused clocks
[    0.594334] PM: genpd: Disabling unused power domains
[    0.608307] mmc0: SDHCI controller on 1000fff000.mmc [1000fff000.mmc] using ADMA 64-bit
[    0.751907] mmc0: new UHS-I speed SDR104 SDHC card at address 1388
[    0.752080] mmcblk0: mmc0:1388 MSSD0 29.2 GiB
[    0.752895]  mmcblk0: p1 p2
[    0.752964] mmcblk0: mmc0:1388 MSSD0 29.2 GiB (quirks 0x40000000)
[    0.758832] mmc1: SDHCI controller on 1001100000.mmc [1001100000.mmc] using ADMA 64-bit
[    0.759917] Freeing unused kernel memory: 2240K
[    0.759988] Run /init as init process
[    0.759990]   with arguments:
[    0.759992]     /init
[    0.759994]     splash
[    0.759995]   with environment:
[    0.759997]     HOME=/
[    0.759998]     TERM=linux
[    0.788869] mmc1: new UHS-I speed DDR50 SDIO card at address 0001
[    0.840314] usb 3-1: new high-speed USB device number 2 using xhci-hcd
[    0.868176] rp1-firmware rp1_firmware: RP1 Firmware version 23fca1cd776798b50bd3e640ecb242215778e7f8
[    0.880267] input: pwr_button as /devices/platform/pwr_button/input/input0
[    0.886593] rp1-pio 1f00178000.pio: Created instance as pio0
[    0.889817] brcmstb-i2c 107d508200.i2c:  @97500hz registered in interrupt mode
[    0.889953] brcmstb-i2c 107d508280.i2c:  @97500hz registered in interrupt mode
[    0.897299] v3d 1002000000.v3d: [drm] Transparent Hugepage support is recommended for optimal performance on this platform!
[    0.904587] [drm] Initialized v3d 1.0.0 for 1002000000.v3d on minor 0
[    0.915867] vc4-drm axi:gpu: bound 107c580000.hvs (ops vc4_hvs_ops [vc4])
[    0.919484] Registered IR keymap rc-cec
[    0.919532] rc rc0: vc4-hdmi-0 as /devices/platform/soc@107c000000/107c701400.hdmi/rc/rc0
[    0.919574] input: vc4-hdmi-0 as /devices/platform/soc@107c000000/107c701400.hdmi/rc/rc0/input1
[    0.920797] input: vc4-hdmi-0 HDMI Jack as /devices/platform/soc@107c000000/107c701400.hdmi/sound/card0/input2
[    0.926850] vc4-drm axi:gpu: bound 107c701400.hdmi (ops vc4_hdmi_ops [vc4])
[    0.929756] Registered IR keymap rc-cec
[    0.929795] rc rc1: vc4-hdmi-1 as /devices/platform/soc@107c000000/107c706400.hdmi/rc/rc1
[    0.929832] input: vc4-hdmi-1 as /devices/platform/soc@107c000000/107c706400.hdmi/rc/rc1/input3
[    0.930381] input: vc4-hdmi-1 HDMI Jack as /devices/platform/soc@107c000000/107c706400.hdmi/sound/card1/input4
[    0.935350] vc4-drm axi:gpu: bound 107c706400.hdmi (ops vc4_hdmi_ops [vc4])
[    0.935472] vc4-drm axi:gpu: bound 107c500000.mop (ops vc4_txp_ops [vc4])
[    0.935531] vc4-drm axi:gpu: bound 107c501000.moplet (ops vc4_txp_ops [vc4])
[    0.935584] vc4-drm axi:gpu: bound 107c410000.pixelvalve (ops vc4_crtc_ops [vc4])
[    0.935633] vc4-drm axi:gpu: bound 107c411000.pixelvalve (ops vc4_crtc_ops [vc4])
[    0.936229] [drm] Initialized vc4 0.0.0 for axi:gpu on minor 1
[    0.942828] vc4-drm axi:gpu: [drm] Cannot find any crtc or sizes
[    0.946181] vc4-drm axi:gpu: [drm] Cannot find any crtc or sizes
[    0.953523] vc4-drm axi:gpu: [drm] Cannot find any crtc or sizes
[    1.012801] usb 3-1: New USB device found, idVendor=0c45, idProduct=0590, bcdDevice= 1.00
[    1.012807] usb 3-1: New USB device strings: Mfr=2, Product=1, SerialNumber=3
[    1.012811] usb 3-1: Product: Arducam B0590 1080P Day/Night
[    1.012813] usb 3-1: Manufacturer: Arducam Technology Co., Ltd.
[    1.012815] usb 3-1: SerialNumber: SN0001
[    1.353898] EXT4-fs (mmcblk0p2): orphan cleanup on readonly fs
[    1.354413] EXT4-fs (mmcblk0p2): mounted filesystem 8abab6b9-ef90-4fee-ae3d-91079bfae7c1 ro with ordered data mode. Quota mode: none.
[    1.577056] systemd[1]: System time advanced to timestamp on /var/lib/systemd/timesync/clock: Sun 2026-07-12 21:04:58 CDT
[    1.631069] NET: Registered PF_INET6 protocol family
[    1.631372] Segment Routing with IPv6
[    1.631383] In-situ OAM (IOAM) with IPv6
[    1.668647] systemd[1]: systemd 257.13-1~deb13u1 running in system mode (+PAM +AUDIT +SELINUX +APPARMOR +IMA +IPE +SMACK +SECCOMP +GCRYPT -GNUTLS +OPENSSL +ACL +BLKID +CURL +ELFUTILS +FIDO2 +IDN2 -IDN +IPTC +KMOD +LIBCRYPTSETUP +LIBCRYPTSETUP_PLUGINS +LIBFDISK +PCRE2 +PWQUALITY +P11KIT +QRENCODE +TPM2 +BZIP2 +LZ4 +XZ +ZLIB +ZSTD +BPF_FRAMEWORK +BTF -XKBCOMMON -UTMP +SYSVINIT +LIBARCHIVE)
[    1.668656] systemd[1]: Detected architecture arm64.
[    1.676590] systemd[1]: Hostname set to <pi-dogdoor>.
[    1.778213] systemd[1]: bpf-restrict-fs: BPF LSM hook not enabled in the kernel, BPF LSM not supported.
[    1.778344] systemd[1]: Using hardware watchdog 'Broadcom BCM2835 Watchdog timer', version 0, device /dev/watchdog0
[    1.778356] systemd[1]: Watchdog running with a hardware timeout of 1min.
[    1.879644] zram_generator::config[252]: zram0: system has too much memory (8062MB), limit is 0MB, ignoring.
[    2.326773] systemd[1]: Queued start job for default target graphical.target.
[    2.345178] systemd[1]: Created slice system-getty.slice - Slice /system/getty.
[    2.345461] systemd[1]: Created slice system-modprobe.slice - Slice /system/modprobe.
[    2.345680] systemd[1]: Created slice system-rpi\x2dsetup\x2dloop.slice - Slice /system/rpi-setup-loop.
[    2.345901] systemd[1]: Created slice system-serial\x2dgetty.slice - Slice /system/serial-getty.
[    2.346138] systemd[1]: Created slice system-systemd\x2dfsck.slice - Slice /system/systemd-fsck.
[    2.346355] systemd[1]: Created slice system-systemd\x2dzram\x2dsetup.slice - Slice /system/systemd-zram-setup.
[    2.346463] systemd[1]: Created slice user.slice - User and Session Slice.
[    2.346520] systemd[1]: Started systemd-ask-password-wall.path - Forward Password Requests to Wall Directory Watch.
[    2.346674] systemd[1]: Set up automount proc-sys-fs-binfmt_misc.automount - Arbitrary Executable File Formats File System Automount Point.
[    2.346698] systemd[1]: Expecting device dev-disk-by\x2dpartuuid-74e1369a\x2d01.device - /dev/disk/by-partuuid/74e1369a-01...
[    2.346706] systemd[1]: Expecting device dev-dri-card0.device - /dev/dri/card0...
[    2.346716] systemd[1]: Expecting device dev-dri-renderD128.device - /dev/dri/renderD128...
[    2.346725] systemd[1]: Expecting device dev-ttyAMA10.device - /dev/ttyAMA10...
[    2.346732] systemd[1]: Expecting device dev-zram0.device - /dev/zram0...
[    2.346786] systemd[1]: Reached target nss-user-lookup.target - User and Group Name Lookups.
[    2.346813] systemd[1]: Reached target slices.target - Slice Units.
[    2.349278] systemd[1]: Listening on rpcbind.socket - RPCbind Server Activation Socket.
[    2.350340] systemd[1]: Listening on systemd-creds.socket - Credential Encryption/Decryption.
[    2.350420] systemd[1]: Listening on systemd-initctl.socket - initctl Compatibility Named Pipe.
[    2.350489] systemd[1]: Listening on systemd-journald-dev-log.socket - Journal Socket (/dev/log).
[    2.350572] systemd[1]: Listening on systemd-journald.socket - Journal Sockets.
[    2.350604] systemd[1]: systemd-pcrextend.socket - TPM PCR Measurements skipped, unmet condition check ConditionSecurity=measured-uki
[    2.350621] systemd[1]: systemd-pcrlock.socket - Make TPM PCR Policy skipped, unmet condition check ConditionSecurity=measured-uki
[    2.350686] systemd[1]: Listening on systemd-udevd-control.socket - udev Control Socket.
[    2.350743] systemd[1]: Listening on systemd-udevd-kernel.socket - udev Kernel Socket.
[    2.350856] systemd[1]: dev-hugepages.mount - Huge Pages File System skipped, unmet condition check ConditionPathExists=/sys/kernel/mm/hugepages
[    2.352115] systemd[1]: Mounting dev-mqueue.mount - POSIX Message Queue File System...
[    2.352726] systemd[1]: Mounting run-lock.mount - Legacy Locks Directory /run/lock...
[    2.353201] systemd[1]: Mounting sys-kernel-debug.mount - Kernel Debug File System...
[    2.353916] systemd[1]: Mounting sys-kernel-tracing.mount - Kernel Trace File System...
[    2.354062] systemd[1]: auth-rpcgss-module.service - Kernel Module supporting RPCSEC_GSS skipped, unmet condition check ConditionPathExists=/etc/krb5.keytab
[    2.355663] systemd[1]: Starting keyboard-setup.service - Set the console keyboard layout...
[    2.360670] systemd[1]: Starting kmod-static-nodes.service - Create List of Static Device Nodes...
[    2.362037] systemd[1]: Starting modprobe@configfs.service - Load Kernel Module configfs...
[    2.365922] systemd[1]: Starting modprobe@drm.service - Load Kernel Module drm...
[    2.372220] systemd[1]: Starting modprobe@efi_pstore.service - Load Kernel Module efi_pstore...
[    2.373961] systemd[1]: Starting modprobe@fuse.service - Load Kernel Module fuse...
[    2.376530] systemd[1]: systemd-fsck-root.service - File System Check on Root Device skipped, unmet condition check ConditionPathExists=!/run/initramfs/fsck-root
[    2.376669] systemd[1]: systemd-hibernate-clear.service - Clear Stale Hibernate Storage Info skipped, unmet condition check ConditionPathExists=/sys/firmware/efi/efivars/HibernateLocation-8cf2644b-4b0b-428f-9387-6d876050dc67
[    2.380645] systemd[1]: Starting systemd-journald.service - Journal Service...
[    2.385802] systemd[1]: Starting systemd-modules-load.service - Load Kernel Modules...
[    2.385851] systemd[1]: systemd-pcrmachine.service - TPM PCR Machine ID Measurement skipped, unmet condition check ConditionSecurity=measured-uki
[    2.387680] systemd[1]: Starting systemd-remount-fs.service - Remount Root and Kernel File Systems...
[    2.387920] systemd[1]: systemd-tpm2-setup-early.service - Early TPM SRK Setup skipped, unmet condition check ConditionSecurity=measured-uki
[    2.389294] systemd[1]: Starting systemd-udev-load-credentials.service - Load udev Rules from Credentials...
[    2.390986] systemd[1]: Starting systemd-udev-trigger.service - Coldplug All udev Devices...
[    2.395338] systemd[1]: Mounted dev-mqueue.mount - POSIX Message Queue File System.
[    2.395671] systemd[1]: Mounted run-lock.mount - Legacy Locks Directory /run/lock.
[    2.395922] systemd[1]: Mounted sys-kernel-debug.mount - Kernel Debug File System.
[    2.396101] systemd[1]: Mounted sys-kernel-tracing.mount - Kernel Trace File System.
[    2.397580] systemd[1]: Finished kmod-static-nodes.service - Create List of Static Device Nodes.
[    2.397996] systemd[1]: modprobe@configfs.service: Deactivated successfully.
[    2.398143] systemd[1]: Finished modprobe@configfs.service - Load Kernel Module configfs.
[    2.398458] systemd[1]: modprobe@drm.service: Deactivated successfully.
[    2.398592] systemd[1]: Finished modprobe@drm.service - Load Kernel Module drm.
[    2.398840] systemd[1]: modprobe@efi_pstore.service: Deactivated successfully.
[    2.398962] systemd[1]: Finished modprobe@efi_pstore.service - Load Kernel Module efi_pstore.
[    2.400479] systemd[1]: Mounting sys-kernel-config.mount - Kernel Configuration File System...
[    2.405093] systemd[1]: Starting systemd-tmpfiles-setup-dev-early.service - Create Static Device Nodes in /dev gracefully...
[    2.407594] fuse: init (API version 7.45)
[    2.416628] systemd[1]: modprobe@fuse.service: Deactivated successfully.
[    2.416850] systemd[1]: Finished modprobe@fuse.service - Load Kernel Module fuse.
[    2.418620] systemd[1]: Mounted sys-kernel-config.mount - Kernel Configuration File System.
[    2.419364] systemd[1]: Mounting sys-fs-fuse-connections.mount - FUSE Control File System...
[    2.424746] zram: Added device: zram0
[    2.427026] systemd[1]: Finished systemd-udev-load-credentials.service - Load udev Rules from Credentials.
[    2.429144] systemd[1]: Mounted sys-fs-fuse-connections.mount - FUSE Control File System.
[    2.432034] i2c_dev: i2c /dev entries driver
[    2.432821] systemd[1]: Finished systemd-modules-load.service - Load Kernel Modules.
[    2.433715] systemd[1]: Starting systemd-sysctl.service - Apply Kernel Variables...
[    2.436508] systemd-journald[343]: Collecting audit messages is disabled.
[    2.440588] EXT4-fs (mmcblk0p2): re-mounted 8abab6b9-ef90-4fee-ae3d-91079bfae7c1 r/w.
[    2.443429] systemd[1]: Finished systemd-remount-fs.service - Remount Root and Kernel File Systems.
[    2.443771] systemd[1]: regenerate_ssh_host_keys.service - Regenerate SSH host keys skipped, unmet condition check ConditionFirstBoot=yes
[    2.448944] systemd[1]: Starting rpi-resize-swap-file.service - rpi-resize-var-swap-service - resize swapfile...
[    2.450177] systemd[1]: systemd-hwdb-update.service - Rebuild Hardware Database skipped, unmet condition check ConditionNeedsUpdate=/etc
[    2.450281] systemd[1]: systemd-pstore.service - Platform Persistent Storage Archival skipped, unmet condition check ConditionDirectoryNotEmpty=/sys/fs/pstore
[    2.452565] systemd[1]: Starting systemd-random-seed.service - Load/Save OS Random Seed...
[    2.452607] systemd[1]: systemd-tpm2-setup.service - TPM SRK Setup skipped, unmet condition check ConditionSecurity=measured-uki
[    2.456795] systemd[1]: Finished systemd-tmpfiles-setup-dev-early.service - Create Static Device Nodes in /dev gracefully.
[    2.456972] systemd[1]: systemd-sysusers.service - Create System Users skipped, no trigger condition checks were met.
[    2.464969] systemd[1]: Starting systemd-timesyncd.service - Network Time Synchronization...
[    2.471479] systemd[1]: Starting systemd-tmpfiles-setup-dev.service - Create Static Device Nodes in /dev...
[    2.471785] systemd[1]: Started systemd-journald.service - Journal Service.
[    2.496483] systemd-journald[343]: Received client request to flush runtime journal.
[    2.603500] loop0: detected capacity change from 0 to 4194304
[    2.658531] zram: setup backing device /dev/disk/by-backingfile/var-swap
[    2.659727] zram0: detected capacity change from 0 to 4194304
[    2.708019] Adding 2097136k swap on /dev/zram0.  Priority:100 extents:1 across:2097136k SS
[    2.811863] rpi-gpiomem 107d508500.gpiomem: window base 0x107d508500 size 0x00000040
[    2.811944] rpi-gpiomem 107d508500.gpiomem: initialised 1 regions as /dev/gpiomem1
[    2.811998] rpi-gpiomem 107d517c00.gpiomem: window base 0x107d517c00 size 0x00000040
[    2.817814] rpi-gpiomem 107d517c00.gpiomem: initialised 1 regions as /dev/gpiomem2
[    2.817851] mc: Linux media interface: v0.10
[    2.818401] rpi-gpiomem 107d504100.gpiomem: window base 0x107d504100 size 0x00000020
[    2.820998] rpi-gpiomem 107d504100.gpiomem: initialised 1 regions as /dev/gpiomem3
[    2.821070] rpi-gpiomem 107d510700.gpiomem: window base 0x107d510700 size 0x00000020
[    2.821117] rpi-gpiomem 107d510700.gpiomem: initialised 1 regions as /dev/gpiomem4
[    2.821183] rpi-gpiomem 1f000d0000.gpiomem: window base 0x1f000d0000 size 0x00030000
[    2.821710] rpi-gpiomem 1f000d0000.gpiomem: initialised 1 regions as /dev/gpiomem0
[    2.890683] videodev: Linux video capture interface: v2.00
[    3.007176] rpi-hevc-dec 1000800000.codec: Device registered as /dev/video19
[    3.046227] cfg80211: Loading compiled-in X.509 certificates for regulatory database
[    3.059041] Loaded X.509 cert 'benh@debian.org: 577e021cb980e0e820821ba7b54b4961b8b4fadf'
[    3.059248] Loaded X.509 cert 'romain.perier@gmail.com: 3abbc6ec146e09d1b6016ab9d6cf71dd233f0328'
[    3.059549] Loaded X.509 cert 'sforshee: 00b28ddf47aef9cea7'
[    3.059803] Loaded X.509 cert 'wens: 61c038651aabdcf94bd0ac7ff06c7248db18c600'
[    3.079777] uvcvideo 3-1:1.0: Found UVC 1.00 device Arducam B0590 1080P Day/Night (0c45:0590)
[    3.098233] Bluetooth: Core ver 2.22
[    3.099302] NET: Registered PF_BLUETOOTH protocol family
[    3.099421] Bluetooth: HCI device and connection manager initialized
[    3.099461] Bluetooth: HCI socket layer initialized
[    3.099512] Bluetooth: L2CAP socket layer initialized
[    3.099555] Bluetooth: SCO socket layer initialized
[    3.106451] Bluetooth: HCI UART driver ver 2.3
[    3.106467] Bluetooth: HCI UART protocol H4 registered
[    3.106498] Bluetooth: HCI UART protocol Three-wire (H5) registered
[    3.107959] brcmfmac: F1 signature read @0x18000000=0x15264345
[    3.108045] Bluetooth: HCI UART protocol Broadcom registered
[    3.108198] hci_uart_bcm serial0-0: supply vbat not found, using dummy regulator
[    3.108344] hci_uart_bcm serial0-0: supply vddio not found, using dummy regulator
[    3.110699] brcmfmac: brcmf_fw_alloc_request: using brcm/brcmfmac43455-sdio for chip BCM4345/6
[    3.110915] usbcore: registered new interface driver brcmfmac
[    3.122942] usbcore: registered new interface driver uvcvideo
[    3.323707] brcmfmac: brcmf_c_process_txcap_blob: no txcap_blob available (err=-2)
[    3.324015] brcmfmac: brcmf_c_preinit_dcmds: Firmware: BCM4345/6 wl0: Aug 29 2023 01:47:08 version 7.45.265 (28bca26 CY) FWID 01-b677b91b
[    3.356892] usb 3-1: 4:1: cannot get freq at ep 0x84
[    3.420188] usbcore: registered new interface driver snd-usb-audio
[    3.436753] Bluetooth: hci0: BCM: chip id 107
[    3.436963] Bluetooth: hci0: BCM: features 0x2f
[    3.438219] Bluetooth: hci0: BCM4345C0
[    3.438226] Bluetooth: hci0: BCM4345C0 (003.001.025) build 0000
[    3.442906] Bluetooth: hci0: BCM4345C0 'brcm/BCM4345C0.raspberrypi,5-model-b.hcd' Patch
[    4.104941] Bluetooth: hci0: BCM: features 0x2f
[    4.106291] Bluetooth: hci0: BCM43455 37.4MHz Raspberry Pi 3+-0190
[    4.106300] Bluetooth: hci0: BCM4345C0 (003.001.025) build 0382
[    4.106703] Bluetooth: hci0: BCM: Using default device address (m.m.m.m)
[    4.766336] Bluetooth: BNEP (Ethernet Emulation) ver 1.3
[    4.766348] Bluetooth: BNEP filters: protocol multicast
[    4.766361] Bluetooth: BNEP socket layer initialized
[    4.771290] Bluetooth: MGMT ver 1.23
[    4.783837] NET: Registered PF_ALG protocol family
[    4.821371] Bluetooth: RFCOMM TTY layer initialized
[    4.821391] Bluetooth: RFCOMM socket layer initialized
[    4.821408] Bluetooth: RFCOMM ver 1.11
[    5.735753] macb 1f00100000.ethernet eth0: PHY [1f00100000.ethernet-ffffffff:01] driver [Broadcom BCM54213PE] (irq=POLL)
[    5.736637] macb 1f00100000.ethernet eth0: configuring for phy/rgmii-id link mode
[    5.739670] macb 1f00100000.ethernet: gem-ptp-timer ptp clock registered.
[    5.767027] brcmfmac: brcmf_cfg80211_set_power_mgmt: power save enabled
[    7.095310] usb 3-1: 4:1: cannot get freq at ep 0x84
[    7.139188] usb 3-1: 4:1: cannot get freq at ep 0x84
[ 2232.496283] warning: `cat' uses wireless extensions which will stop working for Wi-Fi 7 hardware; use nl80211

EEPROM
------

BOOTLOADER: up to date
   CURRENT: Tue May 26 03:01:25 PM UTC 2026 (1779807685)
    LATEST: Tue May 26 03:01:25 PM UTC 2026 (1779807685)
   RELEASE: default (/usr/lib/firmware/raspberrypi/bootloader-2712/default)
            Use raspi-config to change the release.

