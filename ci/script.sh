set -euxo pipefail

main() {
    cargo build
    cargo test
    cargo run
}

main