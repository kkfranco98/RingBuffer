# 🌀 Fixed-Capacity Ring Buffer for C++

A lightweight **circular buffer** (ring buffer) template

Perfect for **embedded systems** (Arduino, ESP32, STM32, etc.) where you need:

- **Fixed-size storage** with NO dynamic allocation  
- **Automatic overwrite** of oldest data when full  
- **O(1)** `push_back()` and indexed access  
- **STL-like iterators** to use `for(auto x : buffer)`
