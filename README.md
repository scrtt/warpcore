# Warpcore
Star Trek Lamp

#Web Adresses
###### Toggle Lamp on/off
`http://<WARPCORE_ADDRESS>/on`
`http://<WARPCORE_ADDRESS>/off`

#FHEM Cconfig
```
define warpcore dummy
attr warpcore setList on:noArg off:noArg
attr warpcore event-on-change-reading state

define n_warpcore notify warpcore:(on|off) {if($EVENT eq "on"){GetFileFromURL("http://<WARPCORE_ADDRESS>/on")}else{GetFileFromURL("http://<WARPCORE_ADDRESS>/off")}}
```
Change `<WARPCORE_ADDRESS>` to the IP-Adress from your ESP!