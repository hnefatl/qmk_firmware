with import <nixpkgs> {
    crossSystem = {
        config = "aarch64-unknown-linux-gnu";
    };
};

mkShell {
    nativeBuildInputs = [ gnumake ];
    buildInputs = [ avrgcc avrlibc ];
}
