import paho.mqtt.client as mqtt
import json
import random
import time

MQTT_BROKER = "localhost"
MQTT_PORT = 1883
MQTT_TOPIC = "smartchargehub/battery/status"

def generate_fake_data():
    return {
        "voltage": round(random.uniform(3.0, 4.3), 2),
        "current": round(random.uniform(0.5, 1.5), 2),
        "temperature": round(random.uniform(20.0, 65.0), 1)
    }

def main():
    client = mqtt.Client()
    client.connect(MQTT_BROKER, MQTT_PORT, 60)
    client.loop_start()

    try:
        while True:
            data = generate_fake_data()
            payload = json.dumps(data)
            client.publish(MQTT_TOPIC, payload)
            print(f"Published: {payload}")
            time.sleep(1)
    except KeyboardInterrupt:
        print("Simulation stopped.")
    finally:
        client.loop_stop()
        client.disconnect()

if __name__ == "__main__":
    main()
