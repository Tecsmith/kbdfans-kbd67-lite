# Setup instructions

1. Use a fork of, or download, the [`qmk/qmk_firmware`](https://github.com/qmk/qmk_firmware/) repo.

2. If you're using a fork remember to never use the `master` branch, rather create a local branch.

    ```bash
    git branch ts-kbdfans-kbd67-lite
    git checkout ts-kbdfans-kbd67-lite
    ```

3. Create a submodule of this repo:

    ```bash
    git submodule add https://github.com/Tecsmith/kbdfans-kbd67-lite
    ```

4. Create a `custom` folder in the `keyboards` folder and use git to move *(and rename)* the submodule folder to there *(remember to rename the dashes {`-`} for underscores {`_`})*:

    ```bash
    mkdir keyboards/custom
    git mv kbdfans-kbd67-lite keyboards/custom/kbdfans_kbd67_lite
    ```

5. You should be able to compile now:

    ```bash
    make custom/kbdfans_kbd67_lite:vinorodrigues
    ```
