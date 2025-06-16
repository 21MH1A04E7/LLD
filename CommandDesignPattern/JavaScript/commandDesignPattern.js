// Command Interface
class Command {
  execute() {}
  undo() {}
}

// Receivers
class Light {
  on() {
    console.log("Light is ON");
  }

  off() {
    console.log("Light is OFF");
  }
}

class Fan {
  on() {
    console.log("Fan is ON");
  }

  off() {
    console.log("Fan is OFF");
  }
}

// Concrete Command for Light
class LightCommand extends Command {
  constructor(light) {
    super();
    this.light = light;
  }

  execute() {
    this.light.on();
  }

  undo() {
    this.light.off();
  }
}

// Concrete Command for Fan
class FanCommand extends Command {
  constructor(fan) {
    super();
    this.fan = fan;
  }

  execute() {
    this.fan.on();
  }

  undo() {
    this.fan.off();
  }
}

// Invoker: Remote Controller
class RemoteController {
  constructor() {
    this.numButtons = 4;
    this.buttons = Array(this.numButtons).fill(null);
    this.buttonPressed = Array(this.numButtons).fill(false);
  }

  setCommand(index, command) {
    if (index >= 0 && index < this.numButtons) {
      this.buttons[index] = command;
      this.buttonPressed[index] = false;
    }
  }

  pressButton(index) {
    if (index >= 0 && index < this.numButtons && this.buttons[index]) {
      if (!this.buttonPressed[index]) {
        this.buttons[index].execute();
      } else {
        this.buttons[index].undo();
      }
      this.buttonPressed[index] = !this.buttonPressed[index];
    } else {
      console.log(`No command assigned at button ${index}`);
    }
  }
}

// Main
const livingRoomLight = new Light();
const ceilingFan = new Fan();

const remote = new RemoteController();

remote.setCommand(0, new LightCommand(livingRoomLight));
remote.setCommand(1, new FanCommand(ceilingFan));

console.log("--- Toggling Light Button 0 ---");
remote.pressButton(0);
remote.pressButton(0);

console.log("--- Toggling Fan Button 1 ---");
remote.pressButton(1);
remote.pressButton(1);

console.log("--- Pressing Unassigned Button 2 ---");
remote.pressButton(2);
