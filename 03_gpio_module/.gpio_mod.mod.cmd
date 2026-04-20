savedcmd_gpio_mod.mod := printf '%s\n'   gpio_mod.o | awk '!x[$$0]++ { print("./"$$0) }' > gpio_mod.mod
