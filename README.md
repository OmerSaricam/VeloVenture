# VeloVenture: Realistic Bicycle Simulation

## Purpose of the Project
VeloVenture is an interactive **bicycle simulation system** that combines **hardware and software** to create an immersive cycling experience. The system integrates **sensor-equipped bicycles**, **facial recognition for authentication**, and **real-time motion control** to provide users with a **realistic cycling adventure** within a game environment.

## Features
- **Realistic Cycling Simulation:** Users experience natural pedaling resistance, steering, and terrain feedback.
- **Interactive Game Modes:**
  - **Free Roaming Mode:** Explore the environment freely.
  - **Race Mode:** Compete against personal best times.
- **Sensor Integration:** Tracks speed, steering direction, and pedaling force.
- **Facial Recognition:** Enables password-free login.
- **Physics-Based Motion Control:** Adjusts resistance based on terrain slopes and ramps.
- **Game Engine Integration:** Developed using **Unreal Engine 5** for high-fidelity graphics and physics.

## System Architecture
The project is divided into **four main modules**:
1. **Sensor Processing Module**: Translates real-world sensor data into game mechanics.
2. **Image Processing Module**: Uses OpenCV and Dlib for facial recognition.
3. **Desktop Simulation Module**: Handles **bike animation, physics, and environment generation**.
4. **Motion Control Module**: Adjusts resistance and controls the feedback system for a more immersive experience.

## Requirements
To build and run the project, you need:
- **C++** for core logic implementation.
- **Unreal Engine 5** for game simulation.
- **ESP32 Microcontroller** for sensor communication.
- **Blender** for 3D model modifications.
- **OpenCV & Dlib** for image processing.
- **Rotary Encoder & Hall Effect Sensors** for motion tracking.
- **Servo Motors** for pedal resistance control.

## Modules Overview
### **1. Sensor Processing Module**
- Collects data from Hall effect and rotary encoder sensors.
- Converts real-time data into steering and speed information.
- Communicates with the game engine via serial communication.

### **2. Image Processing Module**
- Uses OpenCV and Dlib for facial recognition.
- Grants access to the simulation based on user authentication.
- Provides personalized gaming experiences.

### **3. Desktop Simulation Module**
- Handles **bike animation, physics, and environment interactions**.
- Processes game events such as race objectives and obstacles.
- Creates dynamic terrains and lighting effects.

### **4. Motion Control Module**
- Controls the servo motor for adjusting pedal resistance.
- Simulates uphill/downhill effort using real-world physics.
- Enhances realism by adapting the simulation environment dynamically.

## Results Summary
- **Accurate steering and speed detection using real-time sensors.**
- **Seamless facial recognition for password-free login.**
- **Realistic resistance feedback for immersive gameplay.**
- **Smooth integration with Unreal Engine for high-quality graphics and physics.**

## Additional Resources
- [Project Website](https://veloventure1.wixsite.com/home)
- [Demo Video 1](https://www.youtube.com/watch?v=K-N3bh40SfM&t=6s)
- [Demo Video 2](https://www.youtube.com/watch?v=egQUI4KQWJs&t=2s)



## Developers  
Meet our team! Feel free to check out our profiles:  

- [Kubilay Yazman](https://github.com/noktahesefe)  
- [Ömer Sarıçam](https://github.com/OmerSaricam)  
- [Reşit Aydın](https://github.com/resitaydin)  
- [Sare Nur Aydın](https://github.com/sareydn)  
- [Buket Gençer](https://github.com/buketgencer)  
- [Ahmet H. Sevinç](https://github.com/Ahmet-Hakan)  
- [Enes Patır](https://github.com/enespatir07)  


For more details, refer to the `Project Report.pdf` included in this repository.


