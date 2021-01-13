/*  Copyright 240 Timothy Gedney
 *
 *  Expanded upon the provided methods in the .h file
 */

#include <inc/smart_appliance.h>
#include <string>
using std::string;
using std::to_string;

namespace exam3 {

SmartAppliance::~SmartAppliance() {
//  empty
}

SmartLight::SmartLight() {
  light = false;
  lightOnOff = false;
}

const string SmartLight::Activate() {
  if (light) {
    return "Light active";
  } else {
    light = true;
    return "Light activated";
  }
}

const string SmartLight::Deactivate() {
  if (light) {
    light = false;
    return "Light deactivated";
  } else {
    return "";
  }
}

const string SmartLight::Set(unsigned int setting) {
  if (!light) {
    return "";
  } else {
    if (!lightOnOff && setting > 0) {
      lightOnOff = true;
      return "Light set from off to on";
    } else if (lightOnOff && setting > 0) {
      return "Light set on";
    } else if (!lightOnOff && setting == 0) {
      return "Light set off";
    } else if (lightOnOff && setting == 0) {
      lightOnOff = false;
      return "Light set from on to off";
    }
  }
  return "";
}

SmartThermostat::SmartThermostat() {
  thermostat = false;
  set = 101;
}

const string SmartThermostat::Activate() {
  if (thermostat) {
    return "Thermostat active";
  } else {
    thermostat = true;
    return "Thermostat activated";
  }
}

const string SmartThermostat::Deactivate() {
  if (thermostat) {
    thermostat = false;
    return "Thermostat deactivated";
  } else {
    return "";
  }
}

const string SmartThermostat::Set(unsigned int setting) {
  unsigned int temperature = Temperature(setting);
  unsigned int temp = set;
  if (!thermostat) {
    return "";
  } else {
    if (set == 101 || temperature != set) {
      set = temperature;
      return "Thermostat set from " + to_string(temp) +
             " to " + to_string(temperature);
    } else {
      return "Thermostat set to " + to_string(set);
    }
  }
}

//  calcuates temperature from percentage
const unsigned int SmartThermostat::Temperature(unsigned int setting) {
  unsigned int temp = 40;
  double range = 60;
  double settingDbl = setting;
  settingDbl /= 100;
  range *= settingDbl;
  int rangeCheck = range;

  //  correctly rounds if >= 0.5
  if (range - rangeCheck >= 0.5) {
    range++;
  }
  temp += range;

  return temp;
}
}  //  namespace exam3