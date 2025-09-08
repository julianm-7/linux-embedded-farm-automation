class LidarInterface:
    def __init__(self):
        print("[LiDAR] Initialized")

    def scan(self):
        print("[LiDAR] Scanning...")
        # Return data
        return {"distance": 1.5, "unit": "meters"}

if __name__ == "__main__":
    lidar = LidarInterface()
    print(lidar.scan())
