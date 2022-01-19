/* Strandtest_behaviour - converting arduino sample code into behavour table template
 *  This code will take the example/adrafruit neopixel/strandtest code and convert it into
 *  a creative coding template. this code is an exercise to learn how the template works 
 *  before adding creative code.
 */
#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
  #include <avr/power.h>
#endif

//Which pin the neopixel is connected to
#define PIN 3
//total number of rings we use
#define ringTotal 16

//this is the varable that will control what behaviour happens when. In this code, it is just going
//to cycle through them, so where on the table do you want to start?
int action = 0;

//the set of cases that make up my performance
int lightShow[] = {
7,0,6,0,5,8,9,10,0,3,7,2,1,2,0
}; 
//0 - stops ring from showing colours
//1 - sand from the shore of a beach
//2 - water going onto the shore
//3 - represents splashes of water when waves hit eachother
//4 - supposed to represent the aubiance of the ocean and its calmness
//5 - represents a big splash in the water
//6 - wave that starts high and crashes fast into the water
//7 - the ocean as it is when there are little to no waves
//8 - represents huge crashes in waves
//9 - water crashing into rocks
//10 - just a rock

int sine[] = {
   4,  3,  2,  1,  0, 5,6,7,8};
   //use for sineP
int sine2[] = {
   4,3,2,1,0,5,6,7,8,9,10,11,12,13,14,15};
   //use for sineQ
int sine3[] = {
   0,1,2,3,4};
   //use for sineW
int sine4[] = {
   5,6,7,8,9,10,11,12,13,14,15,16};
   //sineW again
int crash[] = {
  3,4,5,6,7,8,9,10,11};
  //use by crashC

   
//this value represents how long the array is or how many light show acts we have in the light performance
//the number should match the array number
int lightShowLength = 16;
//this value tracks where we are in the light show to display it so it starts at zero, the begining
//number as an array
int lightShowCounter = 0;

// Parameter 1 = number of pixels in strip
// Parameter 2 = Arduino pin number (most are valid)
// Parameter 3 = pixel type flags, add together as needed:
//   NEO_KHZ800  800 KHz bitstream (most NeoPixel products w/WS2812 LEDs)
//   NEO_KHZ400  400 KHz (classic 'v1' (not v2) FLORA pixels, WS2811 drivers)
//   NEO_GRB     Pixels are wired for GRB bitstream (most NeoPixel products)
//   NEO_RGB     Pixels are wired for RGB bitstream (v1 FLORA pixels, not v2)
//   NEO_RGBW    Pixels are wired for RGBW bitstream (NeoPixel RGBW products)

Adafruit_NeoPixel neoring = Adafruit_NeoPixel( ringTotal, PIN, NEO_GRB);

//variables for all of the constant colours used
uint32_t color = neoring.Color(40,160,200); // blue
uint32_t colorB = neoring.Color(101, 67, 33); // brown
uint32_t colorRock = neoring.Color(210,105,30); // rock 
uint32_t nothing = neoring.Color(0,0,0); // nothing

void setup() {
  Serial.begin(9600);
  //Note that this code defines our ring and not a strip, need to add your word for your neopixel
  //ring before the dot on these two words
  neoring.begin();
  neoring.show(); // Initialize all pixels to 'off'
}

void loop() {
  action = lightShow[lightShowCounter];
  actionTable();
  
  delay(50);

  if (lightShowCounter < lightShowLength) {
    //when light show counter is less then the length this line of code needs to move to the next case
    //what variable do we need to add before the "++"
    lightShowCounter++;
  }
  

  action++;
  if (action > 0) {
    action = 0;
  }
}  
uint32_t Wheel(byte WheelPos) {
  WheelPos = 255 - WheelPos;
  if(WheelPos < 85) {
    return neoring.Color(255 - WheelPos * 3, 0, WheelPos * 3);
  }
  if(WheelPos < 170) {
    WheelPos -= 85;
    return neoring.Color(0, WheelPos * 3, 255 - WheelPos * 3);
  }
  WheelPos -= 170;
  return neoring.Color(WheelPos * 3, 255 - WheelPos * 3, 0);
}
