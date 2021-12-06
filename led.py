import serial
import paho.mqtt.client as mqtt

s = serial.Serial('COM3', 9600)

def on_connect(client, userdata, flags, rc):
    print(f'Connected to mqtt broker. Result code: {rc}')
    client.subscribe('FutureHAUS/LED')

def on_message(client, userdata, msg:mqtt.MQTTMessage):
    print(f'Broker sent message: {msg.payload.decode()}')
    s.write(msg.payload)

client = mqtt.Client(client_id='ur mom', transport='websockets')
client.on_connect = on_connect
client.on_message = on_message

host = '10.0.0.115'
port = 9001
print(f'Connecting to MQTT Broker. Host = {host}, Port = {port}')
client.connect(host, port=port)

print('Waiting for message')
client.loop_forever(timeout=5)