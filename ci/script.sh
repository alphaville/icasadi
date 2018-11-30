set -euxo pipefail

main() {
    rustup target list | grep '(default)'
    cargo build --target $TARGET
    cargo test --target $TARGET
    cargo run  --target $TARGET
    cargo doc --no-deps
}

main