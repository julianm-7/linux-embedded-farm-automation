#!/bin/bash
# run_farm.sh - Orchestrates the farm automation workflow

echo "[Farm Script] Starting farm automation workflow..."

# Step 1: Run Python LiDAR interface
echo "[Farm Script] Running LiDAR scan..."
python3 src/lidar_interface.py

# Step 2: Build and run C++ motor control
echo "[Farm Script] Compiling motor control..."
make

echo "[Farm Script] Running motor movement..."
./test_motor

# Step 3: Run cloud ML analysis
echo "[Farm Script] Running cloud ML integration..."
python3 cloud/ml_integration.py

echo "[Farm Script] Workflow complete."
