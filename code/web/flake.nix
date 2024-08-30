{
  description = "WASM game development environment with Nix";

  inputs = {
    nixpkgs.url = "github:NixOS/nixpkgs/nixos-unstable";
  };

  outputs = {
    self,
    nixpkgs,
  }: let
    system = "x86_64-linux";
    pkgs = import nixpkgs {inherit system;};
  in {
    devShells.${system}.default = pkgs.mkShell {
      buildInputs = with pkgs; [
        typescript
        clang_15
        lld_15
      ];

      shellHook = ''
        echo -e "\033[1;36mWelcome to the development shell!\033[0m"
      '';
    };
  };
}
