{
  description = "A Nix-flake-based C/C++ development environment";

  inputs.nixpkgs.url = "https://flakehub.com/f/NixOS/nixpkgs/0.1.*.tar.gz";

  outputs = { self, nixpkgs }:
    let
      supportedSystems = [ "x86_64-linux" "aarch64-linux" "x86_64-darwin" "aarch64-darwin" ];
      forEachSupportedSystem = f: nixpkgs.lib.genAttrs supportedSystems (system: f {
        pkgs = import nixpkgs { inherit system; };
      });
    in
    {
      devShells = forEachSupportedSystem ({ pkgs }: {
        default = pkgs.mkShell.override
          {
            # Override stdenv in order to change compiler:
            # stdenv = pkgs.clangStdenv;
          }
          {
            packages = with pkgs; [
              # Database integration
              sqlite

              clang-tools
              pkg-config
              clang
              cmake
              meson
              ninja
              codespell
              conan
              cppcheck
              doxygen
              gtest
              lcov
              vcpkg
              vcpkg-tool
              python3

            ] ++ (if system == "aarch64-darwin" then [ ] else [ gdb ]);
          };
      });
    };
}

