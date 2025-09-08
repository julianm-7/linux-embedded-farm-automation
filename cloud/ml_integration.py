def analyze_crop(image_path: str = "sample_crop.jpg"):
    """
    Mock cloud ML crop analysis.
    """
    print(f"[Cloud] Analyzing {image_path}...")
    return {"status": "ok", "health": "healthy"}

if __name__ == "__main__":
    result = analyze_crop()
    print(result)
