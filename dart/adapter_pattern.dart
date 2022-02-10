import 'dart:math';

class RoundHole {
  const RoundHole(this._radius);

  final double _radius;

  double getRadius() => _radius;

  bool fits(RoundPeg round_peg) => getRadius() >= round_peg.getRadius();
}

class RoundPeg {
  const RoundPeg(this._radius);

  final double _radius;

  double getRadius() => _radius;
}

class SquarePeg {
  const SquarePeg(this._width);

  final double _width;

  double getWidth() => _width;
}

class SquarePegAdapter extends RoundPeg {
  const SquarePegAdapter(this._squarePeg) : super(0.0);

  final SquarePeg _squarePeg;

  @override
  double getRadius() => _squarePeg.getWidth() * sqrt2 / 2;
}

void main() {
  final hole = new RoundHole(5.0);

  final round_peg = new RoundPeg(5.0);

  print(hole.fits(round_peg));

  final small_sqpeg = new SquarePeg(5.0);
  final large_sqpeg = new SquarePeg(10.0);

  // hole.fits(small_sqpeg);

  final small_sqpeg_adapter = new SquarePegAdapter(small_sqpeg);
  final large_sqpeg_adapter = new SquarePegAdapter(large_sqpeg);

  print(hole.fits(small_sqpeg_adapter));
  print(hole.fits(large_sqpeg_adapter));
}
