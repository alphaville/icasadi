set -euxo pipefail

main() {
    cargo build
    cargo test
    cargo run
    cargo doc --no-deps
}

main