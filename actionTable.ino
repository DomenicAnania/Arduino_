void actionTable() {
  switch(action) {
    
    case 0:
      //stops ring from showing colours
    colorWipe(neoring.Color(0, 0, 0), 50);  // nothing
 
            neoring.show();
    break;

    case 1:
    //once the water hits the sand of a beach
    colorWipe(neoring.Color(101, 67, 33), 50); // Brown  
    break;

    case 2: 
    //the basic representation of a wave
    colorWipe(neoring.Color(40,160,200), 50); // Blue
    break;

    case 3:
    //represents splashes of water when waves hit eachother
    sineP(200);    
    break;

    case 4:
    //supposed to represent the aubiance of the ocean and its loneliness
    colorWipe(neoring.Color(127,127,127), 50); // White
    break;

    case 5:
    //represents a big splash in the water
    sineQ(200);
    break;

    case 6:
    //wave that starts high and crashes into the water
    sineW(200);
    break;

    case 7:
    //the ocean as it is calm
     relax(20);

    break;
        
    case 8:
//represents bigger crashes in waves
    theaterChase(neoring.Color(40,160,200), 50); // Blue 
    

    break;

    case 9:
    //water crashing into rock
     rockStill(20);
     delay(50);
     crashC(200);
   
    

    break;

    case 10:
     colorWipe(neoring.Color(210,105,30), 50); // Brown  

    
    break;
    
  }
}


//starts the colour wipe sequence
void colorWipe(uint32_t c, uint8_t wait) {
  for(uint16_t i=0; i< neoring.numPixels(); i++) {
    //Use your word to represent the neo pixel ring from the orange text Adafruit_NeoPixel...
    neoring.setPixelColor(i, c);
    neoring.show();
    delay(100);
  }
}
//starts the rock crashing sequence
 void crashC(uint8_t wait) {
  for(int i=0; i<9; i++) {
    neoring.setPixelColor(crash[i], color);             // Draw 'head' pixel
    //neoring.setPixelColor(crash[(i + 9 - 4) % 9], 0); // Erase 'tail'
    neoring.show();
    delay(100);
  }
  }

//starts the calm water sequence
void relax(uint8_t wait) {
  uint16_t i, j;

  for(j=0; j<51; j++) {
    for(i=0; i<neoring.numPixels(); i++) {
      neoring.setPixelColor(i, color);
    }
    neoring.show();
    delay(wait);
  }
}

//starts the rock still sequence
void rockStill( uint8_t wait){
  uint16_t i, j;

  for(j=0; j<51; j++) {
    for(i=0; i<neoring.numPixels(); i++) {
      neoring.setPixelColor(i, colorRock);
    }
    neoring.show();
    delay(wait);
  }
}

//starts the theatre chase sequence
void theaterChase(uint32_t c, uint8_t wait) {
  for (int j=0; j<10; j++) {  //do 10 cycles of chasing
    for (int q=0; q < 3; q++) {
      for (uint16_t i=0; i < neoring.numPixels(); i=i+3) {
        neoring.setPixelColor(i+q, c);    //turn every third pixel on
      }
      neoring.show();

      delay(wait);

      for (uint16_t i=0; i < neoring.numPixels(); i=i+3) {
        neoring.setPixelColor(i+q, 0);        //turn every third pixel off
      }
    }
  }
}

//starts the little splash in water sequence
  void sineP(uint8_t wait) {
  for(int i=0; i<9; i++) {
    neoring.setPixelColor(sine[i], color);             // Draw 'head' pixel
    neoring.setPixelColor(sine[(i + 9 - 2) % 9], 0); // Erase 'tail'
    neoring.show();
    delay(200);
  }
  }

//starts the big splash in water sequence
  void sineQ(uint8_t wait) {
  for(int i=0; i<16; i++) {
    neoring.setPixelColor(sine2[i], color);             // Draw 'head' pixel
    neoring.setPixelColor(sine2[(i + 16 - 4) % 16], 0); // Erase 'tail'
    neoring.show();
    delay(200);
  }
  }

//starts the big wave sequence 
    void sineW(uint8_t wait) {
  for(int i=0; i<5; i++) {
    neoring.setPixelColor(sine3[i], color);             // Draw 'head' pixel
    //neoring.setPixelColor(sine3[(i + 4- 2) % 4], 0); // Erase 'tail'
    neoring.show();
    delay(500);
   // neoring.setPixelColor(sine3[i], nothing);
//    neoring.show();
  
  }
  for(int i=0; i<12; i++) {
    neoring.setPixelColor(sine4[i], color);             // Draw 'head' pixel
   //neoring.setPixelColor(sine4[(i + 5- 2) % 5], 0); // Erase 'tail'
    neoring.show();
    delay(100);
    //neoring.setPixelColor(sine4[i], nothing);
//    neoring.show();
   
  }
  }
