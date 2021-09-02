/**************************************************************
 *                  TZXDuino Menu Code:
 *  Menu Button (was motor controll button) opens menu
 *  up/down move through menu, play select, stop back
 *  Menu Options:
 *  TSX Baud Rate:
 *    1200
 *    2400
 *    3600
 *  
 *  Turbo Boost:      Speeds up ZX80/81 TZX/O/P files and Electron UEF files TURN OFF IF NOT USING THESE FILES
 *    On
 *    Off
 *  
 *  Pause @ Start
 *    On
 *    Off
 *    
 *  Gremlin Loader
 *    On
 *    Off
 *    
 *  Save settings to eeprom on exit. 
 */
 void menuMode()
 {
  byte lastbtn=true;
  byte menuItem=0;
  byte subItem=0;
  byte updateScreen=true;
  
  while(!isPressed(BtnStop) || lastbtn)
  {
    if(updateScreen) {
      ////lcd_clearline(0);
      printtextF(PSTR("Menu Screen"),0);
      ////lcd_clearline(1);
      switch(menuItem) {
        
        case 0:
        printtextF(PSTR("TSX Baud Rate"),1);
        break;
        
        case 1:
        printtextF(PSTR("Turbo Boost"),1);
        break;
        
        case 2:
        printtextF(PSTR("Pause @ Start"),1);
        break;

        case 3:
        printtextF(PSTR("Gremlin Loader"),1);
        break;
        
      }
      updateScreen=false;
    }
    
    if(isPressed(BtnDown) && !lastbtn){
      if(menuItem<3) menuItem+=1;
      lastbtn=true;
      updateScreen=true;
    }
    if(isPressed(BtnUp) && !lastbtn) {
      if(menuItem>0) menuItem+=-1;
      lastbtn=true;
      updateScreen=true;
    }

    
    if(isPressed(BtnPlay) && !lastbtn) {
      switch(menuItem){
        
        case 0:
          subItem=0;
          updateScreen=true;
          lastbtn=true;
          while(!isPressed(BtnStop) || lastbtn) {
            if(updateScreen) {
              ////lcd_clearline(0);
              printtextF(PSTR("TSX Baud Rate"),0);
              ////lcd_clearline(1);
              switch(subItem) {
                case 0:                                  
                printtextF(PSTR("1200 Baud"),1);
                if(BAUDRATE==1200) printtextF(PSTR("1200 Baud *     "),1);
                break;
                case 1:        
                  printtextF(PSTR("2400 Baud"),1);
                  if(BAUDRATE==2400) printtextF(PSTR("2400 Baud *     "),1);
                break;
                case 2:                  
                printtextF(PSTR("3600 Baud"),1);
                if(BAUDRATE==3600) printtextF(PSTR("3600 Baud *     "),1);
                break;                
              }
              updateScreen=false;
            }
                    
            if(isPressed(BtnDown) && !lastbtn){
              if(subItem<2) subItem+=1;
              lastbtn=true;
              updateScreen=true;
            }
            if(isPressed(BtnUp) && !lastbtn) {
              if(subItem>0) subItem+=-1;
              lastbtn=true;
              updateScreen=true;
            }
            if(isPressed(BtnPlay) && !lastbtn) {
              switch(subItem) {
                case 0:
                  BAUDRATE=1200;
                break;
                case 1:
                  BAUDRATE=2400;
                break;
                case 2:
                  BAUDRATE=3600;
                break;
              }
              updateScreen=true;
              lastbtn=true;
            }
            if(!isPressed(BtnDown) && !isPressed(BtnUp) && !isPressed(BtnPlay) && !isPressed(BtnStop)) lastbtn=false;
          }
          lastbtn=true;
          updateScreen=true;
        break;
        
        case 1:
          subItem=0;
          updateScreen=true;
          lastbtn=true;
          while(!isPressed(BtnStop) || lastbtn) {
            if(updateScreen) {
              //lcd_clearline(0);
              printtextF(PSTR("Turbo Boost"),0);
              //lcd_clearline(1);
              switch(subItem) {
                case 0:
                  printtext("On",1);
                  if(uefTurboMode==1) printtextF(PSTR("On  *           "),1);
                break;
                case 1:
                  printtext("Off",1);
                  if(uefTurboMode==0) printtextF(PSTR("Off *           "),1);
                break;                
              }
              updateScreen=false;
            }
                    
            if(isPressed(BtnDown) && !lastbtn){
              if(subItem<1) subItem+=1;
              lastbtn=true;
              updateScreen=true;
            }
            if(isPressed(BtnUp) && !lastbtn) {
              if(subItem>0) subItem+=-1;
              lastbtn=true;
              updateScreen=true;
            }
            if(isPressed(BtnPlay) && !lastbtn) {
              switch(subItem) {
                case 0:
                  uefTurboMode=1;
                break;
                case 1:
                  uefTurboMode=0;
                break;
              }
              lastbtn=true;
              updateScreen=true;
            }
            //if(digitalRead(btnDown) && digitalRead(btnUp) && digitalRead(btnPlay) && digitalRead(btnStop)) lastbtn=false;
            if(!isPressed(BtnDown) && !isPressed(BtnUp) && !isPressed(BtnPlay) && !isPressed(BtnStop)) lastbtn=false;
          }
          lastbtn=true;
          updateScreen=true;
        break;

        case 2:
          subItem=0;
          updateScreen=true;
          lastbtn=true;
          while(!isPressed(BtnStop) || lastbtn) {
            if(updateScreen) {
              //lcd_clearline(0);
              printtextF(PSTR("Pause @ Start"),0);
              //lcd_clearline(1);
              switch(subItem) {
                case 0:
                  printtext("On",1);
                  if(PauseAtStart==true) printtextF(PSTR("On  *           "),1);
                break;
                
                case 1:
                  printtext("Off",1);
                  if(PauseAtStart==false) printtextF(PSTR("Off *           "),1);
                break;                
              }
              updateScreen=false;
            }
                    
            if(isPressed(BtnDown) && !lastbtn){
              if(subItem<1) subItem+=1;
              lastbtn=true;
              updateScreen=true;
            }
            if(isPressed(BtnUp) && !lastbtn) {
              if(subItem>0) subItem+=-1;
              lastbtn=true;
              updateScreen=true;
            }
            if(isPressed(BtnPlay) && !lastbtn) {
              switch(subItem) {
                case 0:
                  PauseAtStart=true;
                break;
                case 1:
                  PauseAtStart=false;
                break;
              }
              lastbtn=true;
              updateScreen=true;
            }
            if(!isPressed(BtnDown) && !isPressed(BtnUp) && !isPressed(BtnPlay) && !isPressed(BtnStop)) lastbtn=false;
          }
          lastbtn=true;
          updateScreen=true;
        break;

        case 3:
          subItem=0;
          updateScreen=true;
          lastbtn=true;
          while(!isPressed(BtnStop) || lastbtn) {
            if(updateScreen) {
              //lcd_clearline(0);
              printtextF(PSTR("Gremlin Loader"),0);
              //lcd_clearline(1);
              switch(subItem) {
                case 0:
                  printtext("On",1);
                  if(FlipPolarity==1) printtextF(PSTR("On  *           "),1);
                break;
                
                case 1:
                  printtext("Off",1);
                  if(FlipPolarity==0) printtextF(PSTR("Off *           "),1);
                break;                
              }
              updateScreen=false;
            }
                    
            if(isPressed(BtnDown) && !lastbtn){
              if(subItem<1) subItem+=1;
              lastbtn=true;
              updateScreen=true;
            }
            if(isPressed(BtnUp) && !lastbtn) {
              if(subItem>0) subItem+=-1;
              lastbtn=true;
              updateScreen=true;
            }
            if(isPressed(BtnPlay) && !lastbtn) {
              switch(subItem) {
                case 0:
                  FlipPolarity = 1;
                break;
                case 1:
                  FlipPolarity = 0;
                break;
              }
              lastbtn=true;
              updateScreen=true;
            }
            if(!isPressed(BtnDown) && !isPressed(BtnUp) && !isPressed(BtnPlay) && !isPressed(BtnStop)) lastbtn=false;
          }
          lastbtn=true;
          updateScreen=true;
        break;
        
      }
    }
    if(!isPressed(BtnDown) && !isPressed(BtnUp) && !isPressed(BtnPlay) && !isPressed(BtnStop)) lastbtn=false;
  }
  updateEEPROM();
 }

 void updateEEPROM()
 {
  /* Setting Byte: 
   *  bit 0: 1200
   *  bit 1: 2400
   *  bit 2: 3600
   *  bit 3: n/a
   *  bit 4: n/a
   *  bit 5: Pause @ Start
   *  bit 6: Gremlin Loader
   *  bit 7: UEFTurbo
   */
  byte settings=0;

  switch(BAUDRATE) {
    case 1200:
    settings |=1;
    break;
    case 2400:
    settings |=2;
    break;
    case 3600:
    settings |=4;
    break;
  }
  if(PauseAtStart) settings |=32;
  if(FlipPolarity) settings |=64;
  if(uefTurboMode) settings |=128;
  EEPROM.put(0,settings);
 }

 void loadEEPROM()
 {
  byte settings=0;
  EEPROM.get(0,settings);
  if(!settings) return;
  
  if(bitRead(settings,7)) {
    uefTurboMode=1;
  } else {
    uefTurboMode=0;
  }

  if(bitRead(settings,6)) {
    FlipPolarity=1;
  } else {
    FlipPolarity=0;
  }

  if(bitRead(settings,5)) {
    PauseAtStart=true;
  } else {
    PauseAtStart=false;
  }
  
  if(bitRead(settings,0)) {
    BAUDRATE=1200;
  }
  if(bitRead(settings,1)) {
    BAUDRATE=2400;
  }
  if(bitRead(settings,2)) {
    BAUDRATE=3600;
  }
  //setBaud();
  
 }
