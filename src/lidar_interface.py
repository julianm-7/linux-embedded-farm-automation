import numpy as np
import matplotlib.pyplot as plt
from velodyne_decoder.decoder import VLP32CDecoder

class LidarInterface:
    def __init__(self, model='VLP32C'):
        print(f"[LiDAR] Initialized Velodyne {model} decoder")
        self.decoder = VLP32CDecoder()

    def scan(self, pcap_file='example.pcap'):
        """
        Decode a PCAP file and return structured point cloud data.
        """
        print(f"[LiDAR] Decoding {pcap_file}...")
        point_cloud = self.decoder.decode(pcap_file)
        structured_array = np.array(point_cloud)
        print(f"[LiDAR] Scan complete. Points captured: {len(structured_array)}")
        return structured_array

    def visualize(self, structured_array):
        """
        Visualize the point cloud using matplotlib 3D scatter.
        """
        x = structured_array['x']
        y = structured_array['y']
        z = structured_array['z']

        fig = plt.figure()
        ax = fig.add_subplot(111, projection='3d')
        ax.scatter(x, y, z, s=1)

        ax.set_xlabel('X')
        ax.set_ylabel('Y')
        ax.set_zlabel('Z')
        plt.show()


if __name__ == "__main__":
    lidar = LidarInterface()
    points = lidar.scan('example.pcap')  # Replace with your PCAP file
    lidar.visualize(points)
