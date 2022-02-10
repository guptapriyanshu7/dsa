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
  const hole = RoundHole(5.0);

  const round_peg = RoundPeg(5.0);

  print(hole.fits(round_peg));

  const small_sqpeg = SquarePeg(5.0);
  const large_sqpeg = SquarePeg(10.0);

  // hole.fits(small_sqpeg);

  const small_sqpeg_adapter = SquarePegAdapter(small_sqpeg);
  const large_sqpeg_adapter = SquarePegAdapter(large_sqpeg);

  print(hole.fits(small_sqpeg_adapter));
  print(hole.fits(large_sqpeg_adapter));
}
