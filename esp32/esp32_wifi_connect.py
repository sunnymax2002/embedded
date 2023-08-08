import machine
import network
import socket

# Try: https://microcontrollerslab.com/esp32-esp8266-micropython-web-server/

def http_get(url):
    _, _, host, path = url.split('/', 3)
    addr = socket.getaddrinfo(host, 80)[0][-1]
    s = socket.socket()
    s.connect(addr)
    s.send(bytes('GET /%s HTTP/1.0\r\nHost: %s\r\n\r\n' % (path, host), 'utf8'))
    while True:
        data = s.recv(100)
        if data:
            print(str(data, 'utf8'), end='')
        else:
            break
    s.close()
    
def do_connect():
    wlan = network.WLAN(network.STA_IF)
    wlan.active(True)
    if not wlan.isconnected():
        print('connecting to network...')
        wlan.connect('Airtel_sunn_2815', 'go-away')
        while not wlan.isconnected():
            pass
    print('network config:', wlan.ifconfig())
    # turn LED on
    led = machine.Pin(2, machine.Pin.OUT)
    #led.on()
    led.off()
    
do_connect()
http_get('http://micropython.org/ks/test.html')
http_get('http://wiserbyday.com/index.html')
