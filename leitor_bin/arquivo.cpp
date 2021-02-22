//Lamarck Ferreira da silva 16.1.4322
#include<iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;
typedef struct Registro
{
	int matricula; 
	char nome[30];
	float nota1;
	float nota2;
	float nota3;
	int falta;
}registro;

int main () 
{
	FILE *filealuno;
	FILE *filealunobin;
	Registro aluno;
	
	float media=0;
	char resultado;
	if ((filealuno = fopen("Alunos.txt","r")) == NULL) 
	{
		cout << "Erro na abertura do arquivo\n";
		return 0;
	}
	if ((filealunobin = fopen("Conceitos.bin","w")) == NULL) 
	{
		cout << "Erro na abertura do arquivo\n";
		return 0;
	}
	while (fscanf(filealuno, "%d %[A-Z a-z] %f %f %f %d '/n'", &aluno.matricula, aluno.nome, &aluno.nota1, &aluno.nota2, &aluno.nota3, &aluno.falta) != EOF) 
	{
		fwrite(&aluno, sizeof(aluno), 1, filealunobin);
	}
		
	fclose (filealuno);
	fclose (filealunobin);
	
	if ((filealuno = fopen("Alunos.txt","w")) == NULL) 
	{
		cout << "Erro na abertura do arquivo\n";
		return 0;
	}
	if ((filealunobin = fopen("Conceitos.bin","r")) == NULL) 
	{
		cout << "Erro na abertura do arquivo\n";
		return 0;
	}
	
	
		while (fscanf(filealuno, "%d %[A-Z a-z] %f %f %f %d '/n'", &aluno.matricula, aluno.nome, &aluno.nota1, &aluno.nota2, &aluno.nota3, &aluno.falta) != EOF) 
	{
		media=(aluno.nota1+aluno.nota2+aluno.nota3)/3;
		if(aluno.falta>18)
		{
			resultado='F';
			fwrite (filealunobin, "%d %[A-Z a-z] %[A-Z a-z]'/n'" ,aluno.matricula, aluno.nome, resultado);
		}
		else if(media<6.0)
		{
			resultado='R';
			fwrite (filealunobin, "%d %[A-Z a-z] %[A-Z a-z]'/n'" ,aluno.matricula, aluno.nome, resultado);
		}
		else if(media<7.5)
		{
			resultado='C';
			fwrite (filealunobin, "%d %[A-Z a-z] %[A-Z a-z]'/n'" ,aluno.matricula, aluno.nome, resultado);
		}
		else if(media<9.0)
		{
			resultado='B';
			fwrite (filealunobin, "%d %[A-Z a-z] %[A-Z a-z]'/n'" ,aluno.matricula, aluno.nome, resultado);
		}
		else if(media<=10.0)
		{
			resultado='A';
			fwrite (filealunobin, "%d %[A-Z a-z] %[A-Z a-z]'/n'" ,aluno.matricula, aluno.nome, resultado);
		}
		
		cout << aluno.matricula<<" "<<aluno.nome<<" "<<resultado<<endl;
		
	}
	
	
	return 0;
}