#!/bin/bash
# Orchestrates farm automation workflow

echo "[Farm Script] Starting workflow..."

# Step 1: LiDAR scan
echo "[Farm Script] Running Velodyne LiDAR scan..."
python3 src/lidar_interface.py

# Step 2: Compile and run C++ motor control
echo "[Farm Script] Compiling motor control..."
make

echo "[Farm Script] Running full grid scan..."
./test_motor

# Step 3: Run cloud ML analysis
echo "[Farm Script] Running cloud ML integration..."
python3 cloud/ml_integration.py

echo "[Farm Script] Workflow complete."
