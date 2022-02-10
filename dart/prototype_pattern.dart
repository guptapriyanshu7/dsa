abstract class Shape {
  const Shape({
    int? x,
    int? y,
    String? color,
  })  : X = x ?? 0,
        Y = y ?? 0,
        color = color ?? 'blue';

  Shape.clone(Shape shape)
      : X = shape.X,
        Y = shape.Y,
        color = shape.color;

  final int X;
  final int Y;
  final String color;

  Shape clone();
}

class Rectangle extends Shape {
  const Rectangle({
    this.height = 1,
    this.width = 1,
    int? X,
    int? Y,
    String? color,
  }) : super(x: X, y: Y, color: color);

  Rectangle._clone(Rectangle source)
      : width = source.width,
        height = source.height,
        super.clone(source);

  final int width;
  final int height;

  @override
  Shape clone() {
    return Rectangle._clone(this);
  }
}

class Circle extends Shape {
  const Circle({
    this.radius = 1,
    int? X,
    int? Y,
    String? color,
  }) : super(x: X, y: Y, color: color);

  Circle._clone(Circle source)
      : radius = source.radius,
        super.clone(source);

  final int radius;

  @override
  Shape clone() {
    return Circle._clone(this);
  }
}

class Application {
  Application() {
    const circle = Circle();
    shapes.add(circle);

    final anotherCircle = circle.clone();
    shapes.add(anotherCircle);

    const rectangle = Rectangle();
    shapes.add(rectangle);
  }

  final shapes = <Shape>[];

  void businessLogic() {
    final newShapes = <Shape>[];

    for (final shape in shapes) {
      newShapes.add(shape.clone());
    }

    newShapes.forEach((shape) {
      print(shape);
    });
  }
}

void main() {
  final app = Application();

  app.shapes.forEach((shape) {
    print(shape);
  });

  print('\n');

  app.businessLogic();
}
