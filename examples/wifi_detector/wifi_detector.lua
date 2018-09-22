wifi.setmode(wifi.STATIONAP)
wifi.eventmon.register(wifi.eventmon.AP_PROBEREQRECVED, function(event)
  print("MAC: "..event.MAC.." RSSI: "..event.RSSI)
end)
