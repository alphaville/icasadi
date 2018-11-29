set -euxo pipefail

main() {
    make build
    make test
}

main