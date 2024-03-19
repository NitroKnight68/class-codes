import time
import picamera
print("HI")
# Initialize the camera
camera = picamera.PiCamera()
print("HI")
camera.brightness = 60  
camera.contrast = 50    
camera.resolution = (1920, 1080)  
#camera.image_effect = 'negative'  # Apply image effect (e.g., 'negative', 'sketch', etc.)
print("HI")
# Capture a picture
camera.start_preview()
print("1")
time.sleep(2)
print("2")
camera.capture('pic.jpg')
print("3")
camera.stop_preview()
print("done")

# Wait for a moment before capturing video
time.sleep(1)

# Start recording a video
camera.start_recording('example_video.h264')
time.sleep(10)  # Record for 10 seconds (adjust as needed)
camera.stop_recording()
print("done")

# Close the camera connection
camera.close()