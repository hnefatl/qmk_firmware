let
    pkgs = import <nixpkgs> { };
    crossPkgs = import <nixpkgs> {
        crossSystem = { config = "avr"; };
    };
in
    pkgs.mkShell {
        nativeBuildInputs = [ pkgs.gnumake pkgs.getopt pkgs.sudo pkgs.avrdude pkgs.pkgsCross.avr.buildPackages.gcc ];
        buildInputs = [ crossPkgs.avrlibc ];
    }
