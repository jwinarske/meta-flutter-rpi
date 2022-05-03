
# Base this image on core-image-base
include recipes-core/images/core-image-base.bb

COMPATIBLE_MACHINE = "^rpi$"

IMAGE_INSTALL:append = "\
    \
    flutter-engine-${FLUTTER_RUNTIME} \
    flutter-pi-${FLUTTER_RUNTIME} \
    ivi-homescreen-${FLUTTER_RUNTIME} \
    flutter-gallery-${FLUTTER_RUNTIME} \
    flutter-linux-plugins-${FLUTTER_RUNTIME} \
    \
    adwaita-icon-theme-cursors \
    geoclue \
    gsettings-desktop-schemas \
    liberation-fonts \    
    libgpiod \
    libserialport \
    networkmanager \
    os-release \
    upower \
    wireless-regdb-static \
    xdg-user-dirs \
    xkeyboard-config \
    \
    packagegroup-flutter-rpi \
    \
    libgpiod-tools i2c-tools spidev-test can-utils \
    "

INIT_MANAGER = "systemd"
DISTRO_FEATURES:remove = "sysvinit x11 usbgadget"
DISTRO_FEATURES:append = " alsa bluetooth usbhost opengl wayland pam security"

COMBINED_FEATURES += "alsa "

LINUX_KERNEL_TYPE = "preempt-rt"
CMDLINE_DEBUG = "quiet"

GPU_MEM = "128"
DISPMANX_OFFLINE = "1"
DISABLE_OVERSCAN = "1"

DISABLE_RPI_BOOT_LOGO = "1"
DISABLE_SPLASH = "1"
IMAGE_FEATURES:remove = "splash"

ENABLE_SPI_BUS = "1"
ENABLE_I2C = "1"
KERNEL_MODULE_AUTOLOAD:rpi += "i2c-dev i2c-bcm2708"
ENABLE_UART = "1"
# SERIAL_CONSOLES = "115200;ttyAMA0"

LICENSE_FLAGS_ACCEPTED += " commercial"

PREFERRED_PROVIDER:libserialport = "6f9b03e"

PREFERRED_PROVIDER:jpeg = "libjpeg-turbo"
PREFERRED_PROVIDER:jpeg-native = "libjpeg-turbo-native"
