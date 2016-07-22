#pragma once
#include <fstream>
namespace GridDrawLine {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::PictureBox^  pictureBox1;
	private: System::Windows::Forms::Button^  button1;
	protected:

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->button1 = (gcnew System::Windows::Forms::Button());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			this->SuspendLayout();
			// 
			// pictureBox1
			// 
			this->pictureBox1->Location = System::Drawing::Point(12, 12);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(906, 451);
			this->pictureBox1->TabIndex = 0;
			this->pictureBox1->TabStop = false;
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(963, 194);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(75, 61);
			this->button1->TabIndex = 1;
			this->button1->Text = L"PUSH";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1067, 475);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->pictureBox1);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			this->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &MyForm::MyForm_Paint);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion
		Bitmap^ bmp = gcnew Bitmap(L"zebra.bmp");
		
		Graphics^ g;
		Pen ^my_pen;
		Color^ my_color;


	private: System::Void MyForm_Load(System::Object^  sender, System::EventArgs^  e) {
		g = pictureBox1->CreateGraphics();
		//my_pen = gcnew SolidBrush();
		
		
	}
	private: System::Void MyForm_Paint(System::Object^  sender, System::Windows::Forms::PaintEventArgs^  e) {

		//g->DrawImage(bmp, 0, 0);
		//g->DrawImage(bmp, 0, bmp->Height);
	}
	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
		

		
		//g->DrawImage(bmp, 0, 0, bmp->Width, bmp->Height);
		
		Pen^ pen = gcnew Pen(Color::DarkBlue);
		pen->Width = 2;
		//g->DrawLine(pen, 0, bmp->Height,  pictureBox1->Width, bmp->Height);
		


		//Draws grid.   vertical lines.
		for (int i = 0; i < 9 ; i++)
		{
			g->DrawLine(pen, 0, bmp->Height * i, pictureBox1->Width, bmp->Height * i);
		}
		// horizontal lines.
		for (int i = 0; i < 10; i++)
		{
			g->DrawLine(pen, bmp->Width * i, 0, bmp->Width * i, pictureBox1->Height);
		}
		
		


		//Places zebra image on grid.
		int pic_location[3][2];
		get_data(pic_location);
		for (int i = 0; i < 3; i++) //loop places image on panel with coordinates
		{
			g->DrawImage(bmp, pic_location[i][0], pic_location[i][1], bmp->Width, bmp->Height);

		}

	}





			 void get_data(int piclocation[][2]) {

				 std::ifstream in_stream;
				 in_stream.open("picloc.txt");
				 int count = 0;
				 while (!in_stream.eof()) {					//stream coordinates from file into array
					 in_stream >> piclocation[count][0];
					 in_stream >> piclocation[count][1];
					 count++;
				 }
			 }

	};
}
