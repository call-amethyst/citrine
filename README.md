# University Math Notes

A collection of mathematical notes written in LaTeX throughout my university studies.

The repository is organized by semester and course. Each course has a `main.tex` document that assembles its chapters and uses a shared document style.

## Downloads

The latest successfully compiled PDFs are published on GitHub Pages:

**[Browse the notes](https://call-amethyst.github.io/citrine/)**

Automated builds are available from the [GitHub Actions workflow](https://github.com/call-amethyst/citrine/actions/workflows/latex.yml).

- **Nightly builds:** run daily; artifacts are retained for 7 days.
- **Weekly builds:** run on Sundays; artifacts are retained for 90 days.
- **Manual builds:** can be triggered from the Actions tab.

To download a build archive, open a successful workflow run and select the relevant artifact.

The Pages site contains the latest successful publication, while Actions artifacts provide temporary build snapshots.

## Repository structure

```text
math-notes/
├── semester-01/
│   ├── analysis-1/
│   │   ├── main.tex
│   │   └── chapters/
│   ├── linear-algebra-1/
│   └── algorithmic-mathematics/
├── styles/
│   ├── cmt.sty
│   └── LICENSE-MIT
├── .github/
│   └── workflows/
│       └── latex.yml
├── .gitignore
├── LICENSE
└── README.md
```

Each course's `main.tex` is the entry point for compiling that course's notes. Shared styling is maintained in `styles/`.

## Building locally

Install a LaTeX distribution with the packages required by the documents, plus `latexmk`.

Compile an individual course from the repository root:

```bash
latexmk -pdf -file-line-error -halt-on-error \
  semester-01/analysis-1/main.tex
```

The shared style file is stored in `styles/`, you can add it to TeX's search path:

```bash
export TEXINPUTS="$PWD/styles//:"
```

The compiled PDF is generated next to the source unless you specify a separate output directory.

## Automated builds

The workflow in `.github/workflows/latex.yml` discovers `main.tex` files throughout the repository and attempts to compile each course independently.

Temporary LaTeX build files are kept outside the source tree. Generated PDFs are packaged as downloadable artifacts and published to GitHub Pages after a successful build on the default branch.

If a course fails to compile, the workflow reports the failure rather than publishing a partial update.

## Acknowledgements

The shared `cmt.sty` document style is derived from the SeniorMars template.

The style file is distributed under its original MIT license. Its copyright and license notices are preserved in `styles/cmt.sty` and `styles/LICENSE-MIT`.

## License

Unless otherwise indicated, original notes in this repository are licensed under the **Creative Commons Attribution-NonCommercial 4.0 International** license (CC BY-NC 4.0).

You may share and adapt these notes for noncommercial purposes, provided you give appropriate attribution, link to the license, and indicate changes where required.

- [CC BY-NC 4.0 license](https://creativecommons.org/licenses/by-nc/4.0/)
- The `cmt.sty` file is separately licensed under MIT, as documented in `styles/LICENSE-MIT`.
- Third-party materials may be subject to separate terms.

Copyright for original notes: [Amy Huang].

## Contributions

Corrections and suggestions are welcome. When reporting an issue, please identify the relevant semester, course, and chapter.
