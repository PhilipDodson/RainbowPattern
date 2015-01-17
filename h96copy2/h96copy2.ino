// NeoPixel Ring simple sketch (c) 2013 Shae Erisson
// released under the GPLv3 license to match the rest of the AdaFruit NeoPixel library
#include <Adafruit_NeoPixel.h>

// Which pin on the Arduino is connected to the NeoPixels?
#define PIN1            6
#define PIN2            8
#define LEDPIN         13
#define RED             0
#define ORANGE        100
#define YELLOW        200
#define YELLOWGREEN   300
#define GREEN         400
#define GREENBLUE     500
#define  BLUEGREEN    600
#define BLUE          700
#define INDIGO        800
#define VIOLET        900
#define MAGENTA      1000

// How many NeoPixels are attached to the Arduino?
#define NUMPIXELS      55

// When we setup the NeoPixel library, we tell it how many pixels, and which pin to use to send signals.
// Note that for older NeoPixel strips you might need to change the third parameter--see the strandtest
// example for more information on possible values.
Adafruit_NeoPixel strip = Adafruit_NeoPixel(NUMPIXELS, PIN1, NEO_GRB + NEO_KHZ800);
//Adafruit_NeoPixel pixels2 = Adafruit_NeoPixel(NUMPIXELS, PIN2, NEO_GRB + NEO_KHZ800);

volatile int state = LOW;


int delayval = 10; // delay for half a second


String msg = "Hello World";
int pixel;



void setup() {
  
    Serial.begin(115200);           // set up Serial library at 9600 bps
  ;  // prints hello with ending line break 
Serial.println("Hello world!"); 
Serial.println("Hello world!");
  msg += String(3);
  
    Serial.println(msg);
  strip.begin(); // This initializes the NeoPixel library.
 // pixels2.begin();
  //strip.setBrightness(30);
  pinMode(LEDPIN,OUTPUT);
  attachInterrupt(0, blink, CHANGE); // interrupt controlled by pin 2
   Serial.println("RED TEST");
    strip.setPixelColor(1,strip.Color(255,0,0));
  strip.show();
    Serial.println("GREEN TEST");
    strip.setPixelColor(2,strip.Color(0,255,0));
  strip.show();
    Serial.println("BLUE TEST");
    strip.setPixelColor(3,strip.Color(0,0,255));
  strip.show();
  delay(5000);
}

void blink()
{
    state = !state;
    digitalWrite(LEDPIN, state);
}
int t = 0; int r1,b1,g1;
void loop() {
  

  //run the rainbow
  rainbow(delayval);
  // run the rainbow cycle
 // rainbowCycle(delayval);
 


}

int getred(int t)
{
  int out;
  if (t > YELLOW && t < GREEN)
  {
    out = 255 - (t - YELLOW);
  }
}

int getblue(int t)
{
  int out;
}

int getgreen(int t)
{
  int out;
  // Increase green from 0 to 128 in 100 time units
  out = t;
}

void rainbowCycle(int wait) {
  int i, j;
 
  for(j=0; j<256; j++) { // 5 cycles of all colors on wheel
    for(i=0; i< strip.numPixels(); i++) { // below makes sense except & 255 operator, need to look that up
     // strip.setPixelColor(i, Wheel(((i * 256 / strip.numPixels()) + j) & 255));
     Wheel2(((i * 256 / strip.numPixels()) + j) & 255);
    strip.show();
delay(8000);
     }
    strip.show();
    delay(wait);
  }
}

void rainbow(uint8_t wait) {
  uint16_t j;
  Serial.println("rainbow");
  for(j=0; j<256; j++) {
    for(pixel=0; pixel<strip.numPixels(); pixel++) {
      // Serial.println("Pixel" + String(pixel));
      //strip.setPixelColor(pixel, Wheel((pixel*255/NUMPIXELS+j) % 255));
      Wheel2(((pixel * 256 / strip.numPixels()) + j) & 255);
 
  // delay(500);
  // strip.show();
 
 
    }
    strip.show();
    delay(wait);
  }
}


void Wheel2(int WheelPos)
{
  if(WheelPos < 85) {
    int r = WheelPos*3;
    int g = 255 - WheelPos * 3;
    int b = 0;
   //  Serial.println(("Pixel" + String(pixel) + " R " + String(r) + " G " + String(g) + " B " + String(b)));
   strip.setPixelColor(pixel,strip.Color(r,g,b));
  return;

  } else if(WheelPos < 170) {
   WheelPos -= 85;
   int r = 255 - WheelPos * 3;
    int g = 0;
    int b = WheelPos * 3;
   //  Serial.println(("Pixel" + String(pixel) + " R " + String(r) + " G " + String(g) + " B " + String(b)));
    strip.setPixelColor(pixel,strip.Color(r,g,b));
   return;
  } else {
   WheelPos -= 170;
   int r = 0;
    int g = WheelPos * 3;
    int b =  255 - WheelPos * 3;
   // Serial.println(("Pixel" + String(pixel) + " R " + String(r) + " G " + String(g) + " B " + String(b)));
      strip.setPixelColor(pixel,strip.Color(r,g,b));
   return;
  }
}
int Wheel(int WheelPos) {
  if(WheelPos < 85) {
    int r = WheelPos*3;
    int g = 255 - WheelPos * 3;
    int b = 0;
   //  Serial.println(("Pixel" + String(pixel) + " R " + String(r) + " G " + String(g) + " B " + String(b)));
   return  strip.Color(r,g,b);
  

  } else if(WheelPos < 170) {
   WheelPos -= 85;
   int r = 255 - WheelPos * 3;
    int g = 0;
    int b = WheelPos * 3;
   //  Serial.println(("Pixel" + String(pixel) + " R " + String(r) + " G " + String(g) + " B " + String(b)));
   return strip.Color(r, g, b);
  } else {
   WheelPos -= 170;
   int r = 0;
    int g = WheelPos * 3;
    int b =  255 - WheelPos * 3;
   // Serial.println(("Pixel" + String(pixel) + " R " + String(r) + " G " + String(g) + " B " + String(b)));
   return strip.Color(r,g,b);
  }
}
