#! /bin/bash

# Source: https://stackoverflow.com/a/24597941
function fail {
    printf '%s\n' "$1" >&2  # Send message to stderr.
    exit "${2-1}"  # Return a code specified by $2 or 1 by default.
}


# This script's directory.
dir="$( cd "$( dirname "${BASH_SOURCE[0]}" )" &> /dev/null && pwd )"
# Read config file.
. "${dir}/.config"

# Required commands.
commands=("ssh")
for c in "${commands[@]}"
do
if ! command -v "${c}" &> /dev/null
then
    fail "${c} could not be found"
fi
done

ssh -p "${ssh_port}" root@localhost << EOF

cd /usr/src/minix/kernel    || exit 1
make && make install    || exit 1

cd /usr/src/minix/servers/ipc   || exit 1
make && make install    || exit 1
cd /usr/src/minix/servers/pm    || exit 1
make && make install    || exit 1
cd /usr/src/minix/servers/sched || exit 1
make && make install    || exit 1

cd /usr/src/lib/libc    || exit 1
make && make install    || exit 1


cd /usr/src/releasetools    || exit 1
make do-hdboot  || exit 1

echo "Rebooting. You can exit with Ctrl+C"
reboot
EOF
