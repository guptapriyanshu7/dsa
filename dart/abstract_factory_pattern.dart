abstract class GUIFactory {
  Button createButton();
  Checkbox createCheckbox();
}

class WinFactory implements GUIFactory {
  Button createButton() => WinButton();
  Checkbox createCheckbox() => WinCheckbox();
}

class MacFactory implements GUIFactory {
  Button createButton() => MacButton();
  Checkbox createCheckbox() => MacCheckbox();
}

abstract class Button {
  void paint();
}

class WinButton implements Button {
  @override
  void paint() {
    print("windows button painted");
  }
}

class MacButton implements Button {
  @override
  void paint() {
    print("mac button painted");
  }
}

abstract class Checkbox {
  void paint();
}

class WinCheckbox implements Checkbox {
  @override
  void paint() {
    print("windows checkbox painted");
  }
}

class MacCheckbox implements Checkbox {
  @override
  void paint() {
    print("mac checkbox painted");
  }
}

class Application {
  late final GUIFactory _factory;
  late final Button _button;
  late final Checkbox _checkBox;

  Application(GUIFactory factory) {
    this._factory = factory;
  }

  void createUI() {
    this._button = _factory.createButton();
    this._checkBox = _factory.createCheckbox();
  }

  void paint() {
    _button.paint();
    _checkBox.paint();
  }
}

class ApplicationConfigurator {
  late final GUIFactory _factory;
  void main() {
    if (config.OS == "Windows")
      _factory = new WinFactory();
    else if (config.OS == "Mac")
      _factory = new MacFactory();
    else
      throw new Exception("Error! Unknown operating system.");

    Application app = new Application(_factory);
    app.createUI();
    app.paint();
  }
}

class config {
  static const OS = "Mac";
}

void main() {
  final appConfig = ApplicationConfigurator();
  appConfig.main();
}
