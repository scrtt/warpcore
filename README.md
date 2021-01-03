# Warpcore
Star Trek Lamp

# Web Adresses
###### Toggle Lamp on
`http://<WARPCORE_ADDRESS>/on`

###### Toggle Lamp off
`http://<WARPCORE_ADDRESS>/off`

# FHEM Config
```
define warpcore dummy
attr warpcore setList on:noArg off:noArg

define n_warpcore notify warpcore:(on|off) {if($EVENT eq "on"){GetFileFromURL("http://<WARPCORE_ADDRESS>/on")}else{GetFileFromURL("http://<WARPCORE_ADDRESS>/off")}}
```
Change `<WARPCORE_ADDRESS>` to the IP-Adress from your ESP!