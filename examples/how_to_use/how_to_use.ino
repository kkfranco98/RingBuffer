#include <RingBuffer.h>

Ring_Buffer<int, 10> buffer;

void setup()
{
    Serial.begin(115200);

    for (int i = 0; i < 10; i++)
    {
        buffer.push_back(i);
    }
}

void loop()
{
    Serial.println("\n----------------------------");
    // Print the buffer with iterator
    Serial.print("Print with iterator: ");
    for (auto x : buffer)
    {
        Serial.print(String(x) + " ");
    }
    Serial.println();

    // Print the buffer with classic for loop
    Serial.print("Print with classic for loop: ");
    for (int i = 0; i < 10; i++)
    {
        Serial.print(String(buffer.at(i)) + " ");
    }
    Serial.println();

    delay(3000);
}