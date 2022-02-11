abstract class Dialog {
  late final Button _okButton;

  Button createButton();

  Button get getOkButton => _okButton;

  void render() {
    _okButton = createButton();
    _okButton.render();
  }
}

class WindowsDialog extends Dialog {
  @override
  Button createButton() {
    return WindowsButton();
  }
}

class WebDialog extends Dialog {
  @override
  Button createButton() {
    return HTMLButton();
  }
}

abstract class Button {
  void render();
  void click(void Function(String msg) func);
}

class WindowsButton implements Button {
  @override
  void render() {}

  @override
  void click(void Function(String msg) func) {
    func("WindowsButton clicked!");
  }
}

class HTMLButton implements Button {
  @override
  void render() {}

  @override
  void click(void Function(String msg) func) {
    func("HTMLButton clicked!");
  }
}

class Application {
  late final Dialog _dialog;

  void initialize() {
    if (config.OS == "Windows")
      _dialog = WindowsDialog();
    else if (config.OS == "Web")
      _dialog = WebDialog();
    else
      throw Exception("Error! Unknown operating system.");
  }

  void main() {
    initialize();
    _dialog.render();
    _dialog.getOkButton.click((msg) {
      print(msg);
    });
  }
}

class config {
  static const OS = "Web";
}

void main() {
  final app = Application();
  app.main();
}
