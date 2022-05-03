FILESEXTRAPATHS:prepend := "${THISDIR}/files:"

SRC_URI += "file://demo.nmconnection"

PACKAGECONFIG:append = " modemmanager ppp"

do_install:append () {
    install -d ${D}${sysconfdir}/NetworkManager/system-connections
    install -m 0600 ${WORKDIR}/demo.nmconnection ${D}${sysconfdir}/NetworkManager/system-connections
}