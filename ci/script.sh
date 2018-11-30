set -euxo pipefail

main() {
    rustup target list | grep '(default)'
    cargo build
    cargo test
    cargo run
    cargo doc --no-deps
}

main