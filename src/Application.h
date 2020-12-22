/*
The MIT License (MIT)

Copyright (c) 2020-2021 riraotech.com

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
*/

#ifndef _MyApplication_h
#define _MyApplication_h

#include <Wire.h>
#include <Adafruit_MPL3115A2.h>
#include <SerialWiFiBridgeApp.h>

class MyApplication : public SerialWiFiBridgeClass
{
private:
    Adafruit_MPL3115A2 *_baro;
    AsyncWebServer *_pServer;

    MyApplication();
    ~MyApplication();

    MyApplication(const MyApplication &);
    MyApplication &operator=(const MyApplication &);

public:
    static MyApplication &getInstance()
    {
        static MyApplication instance;
        return instance;
    }

    void initWebServer();
    void setup();
    void handle();

    float getPressure();
    float getTemperature();
    void setSeaPressure(float pascal);
};

#endif
