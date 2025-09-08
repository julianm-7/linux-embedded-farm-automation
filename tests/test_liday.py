from src.lidar_interface import LidarInterface
import numpy as np

def test_scan():
    lidar = LidarInterface()
    # Using a dummy PCAP file path; in real tests, provide a small test PCAP
    structured_array = lidar.scan('example.pcap')
    
    # Basic checks
    assert isinstance(structured_array, np.ndarray)
    assert 'x' in structured_array.dtype.names
    assert 'y' in structured_array.dtype.names
    assert 'z' in structured_array.dtype.names

if __name__ == "__main__":
    test_scan()
    print("Velodyne LiDAR test passed")
