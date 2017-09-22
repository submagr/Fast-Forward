#Latex

## Tables: 
```latex
\begin{center}
    \begin{tabular}{c|c|c}
        \hline 
        Latent Variable & Type         & Variational Parameters \\ \hine 
        $u_{ik}$        & Gamma        &  $\gamma_{ik}^{sh} , \gamma_{ik}^{rt}$   \\ \hline
        $v_{jk}$        & Gamma        &  $\lambda_{jk}^{sh}, \lambda_{jk}^{rt}$  \\ \hline
        $\zeta_{i}$     & Gamma        &  $\kappa_{i}^{sh} , \kappa_{i}^{rt}$   \\ \hline
        $\eta_{j}$      & Gamma        &  $\tau_{j}^{sh} , \tau_{j}^{rt}$   \\ \hline
        $z_{ij}$        & Multinomial  &  $\phi_{ij}$  \\ \hline
    \end{tabular}	
\end{center}
```
