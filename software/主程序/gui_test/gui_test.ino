#include <stdint.h>
#include <SPI.h>//导入库
#include <TFT_eSPI.h>

#include <WiFi.h>
#include <TJpg_Decoder.h>
#include <pgmspace.h>

#include "SoundData.h"
#include "XT_DAC_Audio.h"

XT_Wav_Class ForceWithYou(Force);     // create an object of type XT_Wav_Class that is used by


XT_DAC_Audio_Class DacAudio(25, 0);   // Create the main player class object.

uint32_t DemoCounter = 0;             // Just a counter to use in the serial monitor



uint16_t  PROGMEM dmaBuffer1[32 * 32]; // Toggle buffer for 32*32 MCU block, 1024bytes
uint16_t  PROGMEM dmaBuffer2[32 * 32]; // Toggle buffer for 32*32 MCU block, 1024bytes
uint16_t* dmaBufferPtr = dmaBuffer1;
bool dmaBufferSel = 0;

















#include <Wire.h>
#include <Adafruit_MPU6050.h>
#include <Adafruit_Sensor.h>

Adafruit_MPU6050 mpu;

#include <BleCombo.h>

extern const uint16_t hander[0x2710] ;
extern const uint16_t sensor[0x2710];
extern const uint16_t bluetooth[0x2710] ;
extern const uint16_t black[0x2710] ;
extern const uint16_t wifi[0x2710];
extern const uint16_t usb[0x2710];
extern const uint16_t touping[0x2710];
extern const uint16_t logo[0x2710];
extern const uint16_t wifired[0x271];
extern const uint16_t wifigreen[0x271];
extern const uint16_t bluetoothred[0x271];
extern const uint16_t bluetoothgreen[0x271];
extern const uint16_t mpured[0x271];
extern const uint16_t mpugreen[0x271];


TFT_eSPI tft = TFT_eSPI();



TFT_eSprite clk = TFT_eSprite(&tft);
char* ssid     = "expert"; //填写你的wifi名字
char* password = "1213812138"; //填写你的wifi密码
int httpPort = 8081; //设置监听端口
WiFiServer server; //初始化一个服务端对象
uint8_t buff[7000] PROGMEM = {0}; //每一帧的临时缓存
uint8_t img_buff[50000] PROGMEM = {0}; //用于存储tcp传过来的图片
uint16_t size_count = 0; //计算一帧的字节大小













int up;
int down;
int left;
int right;
int selection;
int start;
int a;
int b;
int c;
int d;
int e;

int back;


int t;





int i;
int wide;






int flag1 = 0;
int panduan = 0;
int handerpanduan1;
int handerpanduan2;

int serialpanduan;


int bluetoothpanduan;







bool tft_output(int16_t x, int16_t y, uint16_t w, uint16_t h, uint16_t* bitmap)
{
  if ( y >= tft.height() ) return 0;

  // Double buffering is used, the bitmap is copied to the buffer by pushImageDMA() the
  // bitmap can then be updated by the jpeg decoder while DMA is in progress
  if (dmaBufferSel) dmaBufferPtr = dmaBuffer2;
  else dmaBufferPtr = dmaBuffer1;
  dmaBufferSel = !dmaBufferSel; // Toggle buffer selection
  //  pushImageDMA() will clip the image block at screen boundaries before initiating DMA
  tft.pushImageDMA(x, y, w, h, bitmap, dmaBufferPtr); // Initiate DMA - blocking only if last DMA is not complete
  return 1;
}

byte loadNum = 6;
void loading1(byte delayTime) { //启动动画
  clk.setColorDepth(8);

  clk.createSprite(200, 50);
  clk.fillSprite(0x0000);

  clk.drawRoundRect(0, 0, 200, 16, 8, TFT_RED);
  clk.fillRoundRect(3, 3, loadNum, 10, 5, TFT_RED);
  clk.setTextDatum(CC_DATUM);
  clk.setTextColor(TFT_RED, 0x0000);
  clk.drawString("Connecting to WiFi", 100, 40, 2);
  clk.pushSprite(60, 100); //20 110
  clk.deleteSprite();
  loadNum += 1;
  if (loadNum >= 195) {
    loadNum = 195;
  }
  delay(delayTime);
}





















void loading(int tim)
{

  for (wide = 0; wide < 200; wide++)
  {

    tft.fillRoundRect(60 , 200, wide, 15, 6, TFT_RED);

    delay(tim);

  }



}

void changelogo (void)
{

  tft.pushImage(120, 60, 100, 100, logo);
  for (wide = 0; wide < 200; wide++)
  {

    tft.fillRoundRect(60 , 200, wide, 15, 6, TFT_RED);

    delay(6);

  }


  tft.fillScreen(TFT_BLACK);//黑色

}





void change1 (void)
{
  DacAudio.FillBuffer();
  DacAudio.Play(&ForceWithYou);

  for (i = 110; i < 320; i++)
  {
    tft.pushImage(i, 60, 100, 100, hander);
    tft.pushImage(i - 210, 60, 100, 100, bluetooth);
    delay(5);

    tft.pushImage(i, 60, 100, 100, black);
    tft.pushImage(i - 210, 60, 100, 100, black);
    i = i + 10;

  }
  tft.pushImage(110, 60, 100, 100, bluetooth);

}

void change2 (void)
{
  DacAudio.FillBuffer();
  DacAudio.Play(&ForceWithYou);
  for (i = 110; i < 320; i++)
  {
    tft.pushImage(i, 60, 100, 100, bluetooth);
    tft.pushImage(i - 210, 60, 100, 100, wifi);
    delay(5);

    tft.pushImage(i, 60, 100, 100, black);
    tft.pushImage(i - 210, 60, 100, 100, black);
    i = i + 10;

  }
  tft.pushImage(110, 60, 100, 100, wifi);

}

void change3 (void)
{
  DacAudio.FillBuffer();
  DacAudio.Play(&ForceWithYou);
  for (i = 110; i < 320; i++)
  {
    tft.pushImage(i, 60, 100, 100, wifi);
    tft.pushImage(i - 210, 60, 100, 100, sensor);
    delay(5);

    tft.pushImage(i, 60, 100, 100, black);
    tft.pushImage(i - 210, 60, 100, 100, black);
    i = i + 10;

  }
  tft.pushImage(110, 60, 100, 100, sensor);


}

void change4 (void)
{
  DacAudio.FillBuffer();
  DacAudio.Play(&ForceWithYou);
  for (i = 110; i < 320; i++)
  {
    tft.pushImage(i, 60, 100, 100, sensor);
    tft.pushImage(i - 210, 60, 100, 100, usb);
    delay(5);

    tft.pushImage(i, 60, 100, 100, black);
    tft.pushImage(i - 210, 60, 100, 100, black);
    i = i + 10;

  }
  tft.pushImage(110, 60, 100, 100, usb);


}

void change5 (void)
{
  DacAudio.FillBuffer();
  DacAudio.Play(&ForceWithYou);
  for (i = 110; i < 320; i++)
  {
    tft.pushImage(i, 60, 100, 100, usb);
    tft.pushImage(i - 210, 60, 100, 100, touping);
    delay(5);

    tft.pushImage(i, 60, 100, 100, black);
    tft.pushImage(i - 210, 60, 100, 100, black);
    i = i + 10;

  }
  tft.pushImage(110, 60, 100, 100, touping);


}

void change6 (void)
{
  DacAudio.FillBuffer();
  DacAudio.Play(&ForceWithYou);
  for (i = 110; i < 320; i++)
  {
    tft.pushImage(i, 60, 100, 100, touping);
    tft.pushImage(i - 210, 60, 100, 100, hander);
    delay(5);

    tft.pushImage(i, 60, 100, 100, black);
    tft.pushImage(i - 210, 60, 100, 100, black);
    i = i + 10;

  }
  tft.pushImage(110, 60, 100, 100, hander);


}
void handerdraw1(void)
{
  tft.setTextColor(TFT_WHITE, TFT_BLACK);
  tft.fillTriangle(80, 100, 60, 130, 100, 130, TFT_WHITE);
  tft.fillTriangle(80, 180, 60, 150, 100, 150, TFT_WHITE);
  tft.fillTriangle(20, 140, 50, 125, 50, 160 , TFT_WHITE);
  tft.fillTriangle(140, 140, 110, 125, 110, 160, TFT_WHITE);
  tft.setTextSize(3);
  tft.setCursor(50, 72, 1);
  tft.print("ROUP");//显示文字
  tft.setTextSize(3);
  tft.setCursor(50, 188, 1);
  tft.print("RODO");//显示文字

  tft.setTextSize(3);
  tft.setCursor(25, 100, 1);
  tft.print("a");//显示文字

  tft.setTextSize(3);
  tft.setCursor(122, 100, 1);
  tft.print("d");//显示文字



  tft.fillRect(225, 105, 30, 30,  TFT_WHITE);
  tft.fillRect(225, 150, 30, 30,  TFT_WHITE);
  tft.fillRect(180, 130, 30, 30, TFT_WHITE);
  tft.fillRect(270, 130, 30, 30,   TFT_WHITE);
  tft.setTextSize(3);
  tft.setCursor(187, 100, 1);
  tft.print("U");//显示文字
  tft.setTextSize(3);
  tft.setCursor(232, 188, 1);
  tft.print("D");//显示文字

  tft.setTextSize(3);
  tft.setCursor(232, 72, 1);
  tft.print("L");//显示文字

  tft.setTextSize(3);
  tft.setCursor(281, 100, 1);
  tft.print("R");//显示文字
}
















void handerdraw(void)
{
  tft.setTextColor(TFT_WHITE, TFT_BLACK);
  tft.fillTriangle(80, 100, 60, 130, 100, 130, TFT_WHITE);
  tft.fillTriangle(80, 180, 60, 150, 100, 150, TFT_WHITE);
  tft.fillTriangle(20, 140, 50, 125, 50, 160 , TFT_WHITE);
  tft.fillTriangle(140, 140, 110, 125, 110, 160, TFT_WHITE);
  tft.setTextSize(3);
  tft.setCursor(72, 72, 1);
  tft.print("w");//显示文字
  tft.setTextSize(3);
  tft.setCursor(72, 188, 1);
  tft.print("s");//显示文字

  tft.setTextSize(3);
  tft.setCursor(25, 100, 1);
  tft.print("a");//显示文字

  tft.setTextSize(3);
  tft.setCursor(122, 100, 1);
  tft.print("d");//显示文字



  tft.fillRect(225, 105, 30, 30,  TFT_WHITE);
  tft.fillRect(225, 150, 30, 30,  TFT_WHITE);
  tft.fillRect(180, 130, 30, 30, TFT_WHITE);
  tft.fillRect(270, 130, 30, 30,   TFT_WHITE);
  tft.setTextSize(3);
  tft.setCursor(187, 100, 1);
  tft.print("A");//显示文字
  tft.setTextSize(3);
  tft.setCursor(232, 188, 1);
  tft.print("C");//显示文字

  tft.setTextSize(3);
  tft.setCursor(232, 72, 1);
  tft.print("B");//显示文字

  tft.setTextSize(3);
  tft.setCursor(281, 100, 1);
  tft.print("D");//显示文字
}









void setup() {

  pinMode(14, INPUT);
  pinMode(32, INPUT);
  pinMode(27, INPUT);
  pinMode(33, INPUT);
  pinMode(13, INPUT);
  pinMode(16, INPUT);
  pinMode(35, INPUT);
  pinMode(34, INPUT);
  pinMode(26, INPUT);
  pinMode(19, INPUT);
  pinMode(0, INPUT);

  tft.init();
  tft.setSwapBytes(true);// RGB->BGR 加上这句才能正确显示颜色。
  tft.setRotation(3);//横屏
  tft.fillScreen(TFT_BLACK);//黑色
  tft.setTextColor(TFT_WHITE, TFT_BLACK);

  changelogo();

  tft.pushImage(110, 60, 100, 100, hander);









  tft.pushImage(290, 2, 25, 25, wifired);
  tft.pushImage(260, 2, 25, 25, bluetoothred);
  tft.pushImage(5, 2, 25, 25, mpured);
  tft.fillRoundRect(0 , 30, 320, 3, 2, TFT_RED);





}

void loop()
{

  up = digitalRead(14);
  down = digitalRead(32);
  left = digitalRead(27);
  right = digitalRead(33);
  selection = digitalRead(13);
  start = digitalRead(16);
  a = digitalRead(35);
  b = digitalRead(34);
  c = digitalRead(26);
  d = digitalRead(19);


  if (selection == 0)
  {
    flag1 = flag1 + 1;
    selection = 1;

  }
  switch (flag1)
  {
    case 1 :  if (panduan % 6 == 0)
      {
        change1();
        panduan = panduan + 1;
      }
      break;
    case 2 : if (panduan % 6 == 1)
      {
        change2();
        panduan = panduan + 1;
      }
      break;
    case 3 :  if (panduan == 2)
      {
        panduan = panduan + 1;
        change3();
      }
      break;

    case 4 :  if (panduan == 3)
      {
        panduan = panduan + 1;
        change4();
      }
      break;
    case 5 :  if (panduan == 4)
      {
        panduan = panduan + 1;
        change5();
      }
      break;
    case 6 :  if (panduan == 5)
      {
        panduan = panduan + 1;
        change6();
      }
      break;
  }
  if (panduan == 6)
  {
    panduan = 0 ;
  }


  if (flag1 == 6)
  {
    flag1 = 0;
  }


  if (start == 0)
  {

    switch (flag1)
    {

      case 0:
        bluetoothpanduan = bluetoothpanduan + 1;
        if (bluetoothpanduan == 1)
        {
          Keyboard.begin();
          Mouse.begin();
        }




        wide = 0;

        while (!Keyboard.isConnected())
        {


          wide = wide + 2;

          tft.fillRoundRect(60 , 200, wide, 15, 6, TFT_RED);
          if (wide == 200)
          {
            wide = 0;

          }
          delay(60);

        }

        loading(3);

        tft.fillScreen(TFT_BLACK);

        tft.pushImage(290, 2, 25, 25, wifired);
        tft.pushImage(260, 2, 25, 25, bluetoothgreen);
        tft.pushImage(5, 2, 25, 25, mpured);
        tft.fillRoundRect(0 , 30, 320, 3, 2, TFT_RED);
        tft.setTextSize(3);
        tft.setCursor(10, 50, 1);
        tft.setTextColor(TFT_WHITE, TFT_RED);
        tft.print("GenShin");//显示文字
        tft.setTextSize(3);
        tft.setCursor(10, 90  , 1);
        tft.setTextColor(TFT_WHITE, TFT_BLACK);
        tft.print("TikTok");//显示文字
        while (back != 1)
        {
          a = digitalRead(35);
          e = digitalRead(0);
          c = digitalRead(26);



          if (e == 0)
          {
            back = 1;
          }
          if (a == 0)
          {
            handerpanduan1 = handerpanduan1 + 1;
          }
          if (handerpanduan1 == 3)
          {
            handerpanduan1 = 1;
          }
          switch (handerpanduan1)
          {
            case 1: tft.setTextSize(3);
              tft.setCursor(10, 50, 1);
              tft.setTextColor(TFT_WHITE, TFT_RED);
              tft.print("GenShin");//显示文字
              tft.setTextSize(3);
              tft.setCursor(10, 90  , 1);
              tft.setTextColor(TFT_WHITE, TFT_BLACK);
              tft.print("TikTok");//显示文字
              handerpanduan2 = 0;
              break;
            case 2: tft.setTextSize(3);
              tft.setCursor(10, 50, 1);
              tft.setTextColor(TFT_WHITE, TFT_BLACK);
              tft.print("GenShin");//显示文字
              tft.setTextSize(3);
              tft.setCursor(10, 90, 1);
              tft.setTextColor(TFT_WHITE, TFT_RED);
              tft.print("TikTok");//显示文字
              handerpanduan2 = 1;
              break;
          }
          if (c == 0)
          {

            switch (handerpanduan2)
            {
              case 1:




                loading(3);

                tft.fillScreen(TFT_BLACK);

                tft.pushImage(290, 2, 25, 25, wifired);
                tft.pushImage(260, 2, 25, 25, bluetoothgreen);
                tft.pushImage(5, 2, 25, 25, mpured);
                tft.fillRoundRect(0 , 30, 320, 3, 2, TFT_RED);




                handerdraw1();
                while (back != 1)
                {
                  if (Keyboard.isConnected())
                  {
                    up = digitalRead(14);
                    down = digitalRead(32);
                    left = digitalRead(27);
                    right = digitalRead(33);
                    selection = digitalRead(13);
                    start = digitalRead(16);
                    a = digitalRead(35);
                    b = digitalRead(34);
                    c = digitalRead(26);
                    d = digitalRead(19);
                    e = digitalRead(0);
                    if (e == 0)
                    {
                      back = 1;
                      //              Keyboard.write(KEY_ESC);

                    }
                    if (selection == 0 && start == 0)
                    {
                      Keyboard.print("e");
                      selection = 1;
                      start = 1;
                    }
                    if (up == 0 && selection == 0)
                    {
                      Mouse.click(MOUSE_RIGHT);

                      up = 1;
                      selection = 1;
                    }
                    if (left == 0 && selection == 0)
                    {
                      Keyboard.print("q");
                      left = 1;
                      selection = 1;
                    }
                    if (down == 0 && selection == 0)
                    {
                      Keyboard.print(i);
                      b = 1;
                      start = 1;
                      i = i + 1;
                      if (i == 5)
                      {
                        i = 1;
                      }
                    }
                    if (b == 0 && start == 0)
                    {
                      Keyboard.print("m");

                      b = 1;
                      start = 1;
                    }
                    if (b == 0 && d == 0)
                    {
                      Keyboard.print("f");
                      b = 1;
                      d = 1;
                    }
                    if (a == 0 && c == 0)
                    {
                      Keyboard.write(KEY_ESC);
                      a = 1;
                      c = 1;
                    }
                    if (start == 0) {


                      Mouse.click(MOUSE_LEFT);
                      start = 1;

                    }
                    if (selection == 0) {

                      Keyboard.write(KEY_ESC);
                      selection = 1;
                    }
                    if (a == 0) {

                      Mouse.move(0, -10);
                      a = 1;
                    }


                    if (c == 0) {
                      Mouse.move(0, 10);
                      c = 1;
                    }

                    if (b == 0)
                    {
                      Mouse.move(-10, 0);
                      b = 1;
                    }

                    if (d == 0)
                    {
                      Mouse.move(10, 0);
                      d = 1;
                    }
                    if (up == 0)
                    {
                      //              Keyboard.print("w");
                      Mouse.move(0, 0, 5);
                      up = 1;
                    }
                    if (down == 0)
                    {
                      //              Keyboard.print("s");
                      Mouse.move(0, 0, -5);
                      down = 1;
                    }
                    if (left == 0)
                    {
                      Keyboard.print("a");
                      left = 1;
                    }
                    if (right == 0)
                    {
                      Keyboard.print("d");
                      right = 1;
                    }
                    delay(20);

                  }



                }





              case 0:
                loading(3);

                tft.fillScreen(TFT_BLACK);

                tft.pushImage(290, 2, 25, 25, wifired);
                tft.pushImage(260, 2, 25, 25, bluetoothgreen);
                tft.pushImage(5, 2, 25, 25, mpured);
                tft.fillRoundRect(0 , 30, 320, 3, 2, TFT_RED);




                handerdraw();
                while (back != 1)
                {
                  if (Keyboard.isConnected())
                  {
                    up = digitalRead(14);
                    down = digitalRead(32);
                    left = digitalRead(27);
                    right = digitalRead(33);
                    selection = digitalRead(13);
                    start = digitalRead(16);
                    a = digitalRead(35);
                    b = digitalRead(34);
                    c = digitalRead(26);
                    d = digitalRead(19);
                    e = digitalRead(0);
                    if (e == 0)
                    {
                      back = 1;


                    }
                    if (selection == 0 && start == 0)
                    {
                      Keyboard.print("e");
                      selection = 1;
                      start = 1;
                    }
                    if (up == 0 && selection == 0)
                    {
                      Keyboard.print("q");
                      up = 1;
                      selection = 1;
                    }
                    if (left == 0 && selection == 0)
                    {
                      Keyboard.print("q");
                      left = 1;
                      selection = 1;
                    }
                    if (down == 0 && selection == 0)
                    {
                      Keyboard.print(i);
                      b = 1;
                      start = 1;
                      i = i + 1;
                      if (i == 5)
                      {
                        i = 1;
                      }
                    }
                    if (b == 0 && start == 0)
                    {
                      Keyboard.print("m");

                      b = 1;
                      start = 1;
                    }
                    if (b == 0 && d == 0)
                    {
                      Keyboard.print("f");
                      b = 1;
                      d = 1;
                    }
                    if (a == 0 && c == 0)
                    {
                      Keyboard.write(KEY_ESC);
                      a = 1;
                      c = 1;
                    }
                    if (start == 0) {


                      Mouse.click(MOUSE_LEFT);
                      start = 1;

                    }
                    if (selection == 0) {

                      Keyboard.print(" ");
                      selection = 1;
                    }
                    if (a == 0) {

                      Mouse.move(0, -10);
                      a = 1;
                    }


                    if (c == 0) {
                      Mouse.move(0, 10);
                      c = 1;
                    }

                    if (b == 0)
                    {
                      Mouse.move(-10, 0);
                      b = 1;
                    }

                    if (d == 0)
                    {
                      Mouse.move(10, 0);
                      d = 1;
                    }
                    if (up == 0)
                    {
                      Keyboard.print("w");

                      up = 1;
                    }
                    if (down == 0)
                    {
                      Keyboard.print("s");

                      down = 1;
                    }
                    if (left == 0)
                    {
                      Keyboard.print("a");
                      left = 1;
                    }
                    if (right == 0)
                    {
                      Keyboard.print("d");
                      right = 1;
                    }
                    delay(20);

                  }



                }















            }





          }

          delay(120);


        }

        tft.fillScreen(TFT_BLACK);
        tft.pushImage(290, 2, 25, 25, wifired);
        tft.pushImage(260, 2, 25, 25, bluetoothgreen);
        tft.pushImage(5, 2, 25, 25, mpured);
        tft.fillRoundRect(0 , 30, 320, 3, 2, TFT_RED);
        tft.pushImage(110, 60, 100, 100, hander);


        back = 0;

        break;









      case 1: break;
      case 2: break;








      case 3:

        while (!mpu.begin())
        {
          wide = wide + 5;

          tft.fillRoundRect(60 , 200, wide, 15, 6, TFT_RED);

          delay(20);

        }

        loading(3);

        tft.fillScreen(TFT_BLACK);

        tft.pushImage(290, 2, 25, 25, wifired);
        tft.pushImage(260, 2, 25, 25, bluetoothred);
        tft.pushImage(5, 2, 25, 25, mpugreen);
        tft.fillRoundRect(0 , 30, 320, 3, 2, TFT_RED);

        mpu.setAccelerometerRange(MPU6050_RANGE_8_G);
        mpu.setGyroRange(MPU6050_RANGE_500_DEG);
        mpu.setFilterBandwidth(MPU6050_BAND_5_HZ);
        while (back != 1)
        {

          e = digitalRead(0);
          if (e == 0)
          {
            back = 1;
          }
          /* 通过读数获取新的传感器事件 */
          sensors_event_t a, g, temp;
          mpu.getEvent(&a, &g, &temp);
          t = t + 1;
          if (t == 320)
          {
            t = 0;
            tft.fillScreen(TFT_BLACK);
            tft.pushImage(290, 2, 25, 25, wifired);
            tft.pushImage(260, 2, 25, 25, bluetoothred);
            tft.pushImage(5, 2, 25, 25, mpugreen);
            tft.fillRoundRect(0 , 30, 320, 3, 2, TFT_RED);




          }

          tft.drawFastHLine(0, 150, 320, TFT_WHITE ); //水平线
          tft.setTextColor(TFT_RED, TFT_BLACK);
          tft.setTextSize(2);
          tft.setCursor(10, 40, 1);
          tft.print("X:");//显示文字
          tft.setTextSize(2);
          tft.setCursor(50, 40, 1);
          tft.print(a.acceleration.x);//显示文字
          tft.drawPixel( t, 149 - a.acceleration.x * 5 , TFT_RED); // 画点
          tft.drawPixel( t, 150 - a.acceleration.x * 5 , TFT_RED); // 画点
          tft.drawPixel( t, 151 - a.acceleration.x * 5 , TFT_RED); // 画点
          tft.setTextSize(2);
          tft.setCursor(190, 40, 1);
          tft.print(g.gyro.x);//显示文字
          tft.setTextColor(TFT_BLUE, TFT_BLACK);
          tft.setTextSize(2);
          tft.setCursor(10, 60, 1);
          tft.print("Y:");//显示文字
          tft.setTextSize(2);
          tft.setCursor(50, 60, 1);
          tft.print(a.acceleration.y);//显示文字
          tft.drawPixel( t, 149 - a.acceleration.y * 5 , TFT_BLUE); // 画点
          tft.drawPixel( t, 150 - a.acceleration.y * 5 , TFT_BLUE); // 画点
          tft.drawPixel( t, 151 - a.acceleration.y * 5 , TFT_BLUE); // 画点
          tft.setTextSize(2);
          tft.setCursor(190, 60, 1);
          tft.print(g.gyro.y);//显示文字
          tft.setTextColor(TFT_GREEN, TFT_BLACK);
          tft.setTextSize(2);
          tft.setCursor(10, 80, 1);
          tft.print("Z:");//显示文字
          tft.setTextSize(2);
          tft.setCursor(50, 80, 1);
          tft.print(a.acceleration.z);//显示文字
          tft.drawPixel( t, 149 - a.acceleration.z * 5 , TFT_GREEN); // 画点
          tft.drawPixel( t, 150 - a.acceleration.z * 5 , TFT_GREEN); // 画点
          tft.drawPixel( t, 151 - a.acceleration.z * 5 , TFT_GREEN); // 画点

          tft.setTextSize(2);
          tft.setCursor(190, 80, 1);
          tft.print(g.gyro.z);//显示文字


          delay(2);


        }

        tft.fillScreen(TFT_BLACK);

        tft.pushImage(290, 2, 25, 25, wifired);
        tft.pushImage(260, 2, 25, 25, bluetoothred);
        tft.pushImage(5, 2, 25, 25, mpured);
        tft.fillRoundRect(0 , 30, 320, 3, 2, TFT_RED);
        tft.pushImage(110, 60, 100, 100, sensor);

        tft.setTextColor(TFT_WHITE, TFT_BLACK);
        back = 0;

        break;


      case 4:

        loading(3);
        serialpanduan = serialpanduan + 1;
        if (serialpanduan == 1)
        {
          Serial.begin(115200);
        }
        tft.fillScreen(TFT_BLACK);

        tft.pushImage(290, 2, 25, 25, wifired);
        tft.pushImage(260, 2, 25, 25, bluetoothred);
        tft.pushImage(5, 2, 25, 25, mpured);
        tft.fillRoundRect(0 , 30, 320, 3, 2, TFT_RED);







        while (back != 1)
        {

          e = digitalRead(0);
          if (e == 0)
          {
            back = 1;
          }

          tft.setTextColor(TFT_RED, TFT_BLACK);
          tft.setTextSize(2);
          tft.setCursor(0, 36, 1);
          tft.print("Serial 115200 Bps");//显示文字
          // tft.drawRect(5, 5, 230, 60, TFT_WHITE);
          // tft.drawRect(5, 70, 230, 165, TFT_WHITE);
          if (Serial.available())     // 当串口接收到信息后
          {
            tft.setTextColor(TFT_RED, TFT_BLACK);
            tft.setTextSize(2);
            tft.setCursor(0, 36, 1);
            tft.print("Serial 115200 Bps");//显示文字
            tft.setTextColor(TFT_WHITE, TFT_BLACK);
            String serialData = Serial.readString();    // 将接收到的信息使用readString()存储于serialData变量


            tft.setCursor(0, 90, 1);
            tft.print("                                                                                                                                 ");//显示文字
            tft.setCursor(0, 90, 1);
            tft.print(serialData);//显示文字



            delay(10);


          }
          delay(10);
        }

        //        Serial.end();
        tft.fillScreen(TFT_BLACK);

        tft.pushImage(290, 2, 25, 25, wifired);
        tft.pushImage(260, 2, 25, 25, bluetoothred);
        tft.pushImage(5, 2, 25, 25, mpured);
        tft.fillRoundRect(0 , 30, 320, 3, 2, TFT_RED);
        tft.pushImage(110, 60, 100, 100, usb);

        tft.setTextColor(TFT_WHITE, TFT_BLACK);
        back = 0;

        break;






      case 5:

        //        Serial.begin(115200);
        //        tft.begin();
        tft.initDMA();
        tft.setRotation(3);//横屏
        tft.fillScreen(TFT_BLACK);//黑色
        tft.setTextColor(TFT_RED, TFT_BLACK);

        WiFi.begin(ssid, password); //连接wifi
        delay(1000); //等待1秒
        while (WiFi.status() != WL_CONNECTED) {
          for (byte n = 0; n < 10; n++) { //每500毫秒检测一次状态
            loading1(50);
          }
        }
        while (loadNum < 195) { //让动画走完
          loading1(3);
        }
        if (WiFi.status() == WL_CONNECTED) //判断如果wifi连接成功
        {

          //client.setNoDelay(false);//关闭Nagle算法
          //          Serial.println("wifi is connected!");
          //          Serial.print("SSID: ");
          //          Serial.println(WiFi.SSID());
          IPAddress ip = WiFi.localIP();
          //          Serial.print("IP Address: ");
          //          Serial.println(ip);
          //          Serial.println("Port: " + String(httpPort));
          //          tft.setSwapBytes(true);

          tft.fillScreen(TFT_BLACK);//黑色
          tft.pushImage(290, 2, 25, 25, wifigreen);
          tft.pushImage(260, 2, 25, 25, bluetoothred);
          tft.pushImage(5, 2, 25, 25, mpured);
          tft.fillRoundRect(0 , 30, 320, 3, 2, TFT_RED);
          tft.setTextColor(TFT_WHITE, TFT_BLACK);
          tft.drawString("Wifi Have Connected To " + String(WiFi.SSID()), 10, 50, 2);

          tft.drawString("IP: " + ip.toString(), 20, 70, 2);
          tft.drawString("Port: " + String(httpPort), 20, 90, 2);
          //          Serial.println("Waiting a client to connect.........");
          server.begin(httpPort); //服务器启动监听端口号
          server.setNoDelay(true);
        }
        tft.setSwapBytes(0);
        TJpgDec.setJpgScale(1);
        TJpgDec.setSwapBytes(true);
        TJpgDec.setCallback(tft_output);//解码成功回调函数
        uint16_t read_count = 0; //读取buff的长度
        uint8_t pack_size[2];//用来装包大小字节
        uint16_t frame_size;//当前帧大小
        float start_time, end_time; //帧处理开始和结束时间
        float receive_time, deal_time; //帧接收和解码时间

        while (1)
        {
          //沾包问题 recv阻塞，长时间收不到数据就会断开
          //断开连接原因，读取buff太快，上位机发送太快造成buff溢出，清空缓冲区会断开（FLUSH）
          WiFiClient client = server.available(); //尝试建立客户对象
          if (client)
          {
            //            Serial.println("[New Client!]");
            client.write("ok");//向上位机发送下一帧发送指令

            while (client.connected()) //如果客户端处于连接状态client.connected()
            {
              client.write("no");//向上位机发送当前帧未写入完指令
              while (client.available()) {
                while (client.available()) {//检测缓冲区是否有数据
                  if (read_count == 0)
                  {
                    start_time = millis();
                    client.read(pack_size, 2); //读取帧大小
                    frame_size = pack_size[0] + (pack_size[1] << 8);
                  }
                  read_count = client.read(buff, 7000); //向缓冲区读取数据
                  memcpy(&img_buff[size_count], buff, read_count); //将读取的buff字节地址复制给img_buff数组
                  size_count = size_count + read_count; //计数当前帧字节位置
                  //           Serial.println(size_count);
                  if (img_buff[frame_size - 3] == 0xaa && img_buff[frame_size - 2] == 0xbb && img_buff[frame_size - 1] == 0xcc) //判断末尾数据是否当前帧校验位
                  {
                    receive_time = millis() - start_time;
                    deal_time = millis();
                    img_buff[frame_size - 3] = 0; img_buff[frame_size - 2] = 0; img_buff[frame_size - 1] = 0; //清除标志位
                    tft.startWrite();//必须先使用startWrite，以便TFT芯片选择保持低的DMA和SPI通道设置保持配置
                    TJpgDec.drawJpg(0, 0, img_buff, sizeof(img_buff)); //在左上角的0,0处绘制图像——在这个草图中，DMA请求在回调tft_output()中处理
                    tft.endWrite();//必须使用endWrite来释放TFT芯片选择和释放SPI通道吗
                    //            memset(&img_buff,0,sizeof(img_buff));//清空buff
                    size_count = 0; //下一帧
                    read_count = 0;
                    client.write("ok");//向上位机发送下一帧发送指令
                    end_time = millis(); //计算mcu刷新一张图片的时间，从而算出1s能刷新多少张图，即得出最大刷新率
                    //                    Serial.printf("帧大小：%d " , frame_size); Serial.print("MCU处理速度："); Serial.print(1000 / (end_time - start_time), 2); Serial.print("Fps");
                    //                    Serial.printf("帧接收耗时:%.2fms,帧解码显示耗时:%.2fms\n", receive_time, (millis() - deal_time));
                    break;
                  }
                }
              }
            }
            client.stop();
            //            Serial.println("连接中断,请复位重新创建服务端");
          }
        }

        break;











    }



  }



}
