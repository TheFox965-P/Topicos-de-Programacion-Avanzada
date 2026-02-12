#pragma once

#include "OpenCVManager.h"
#include <msclr/marshal_cppstd.h>

namespace ProyectoFP1
{

    using namespace System;
    using namespace System::ComponentModel;
    using namespace System::Windows::Forms;
    using namespace System::Drawing;
    using namespace System::Drawing::Imaging;
    using namespace System::Drawing::Drawing2D;

    public ref class MainForm : public Form
    {
    public:
        MainForm()
        {
            InitializeComponent();
            cvManager = new OpenCVManager();
        }

    protected:
        ~MainForm()
        {
            if (cvManager != nullptr)
                delete cvManager;
        }

    private:
        // =========================
        // OpenCV manager
        // =========================
        OpenCVManager* cvManager;

        // =========================
        // UI controls
        // =========================
        PictureBox^ pictureBox1;
        Button^ btnAbrirCamara;
        Button^ btnCerrarCamara;
        Button^ btnCargarImagen;
        ComboBox^ comboFiltros;
        TrackBar^ trackBar1;
        Timer^ timer1;
        Label^ lblFiltro;
        Label^ lblIntensidad;
        Label^ lblValorIntensidad;
        Panel^ panelControles;
        Panel^ panelVisor;

#pragma region Windows Form Designer generated code
        void InitializeComponent(void)
        {
            this->pictureBox1 = gcnew PictureBox();
            this->btnAbrirCamara = gcnew Button();
            this->btnCerrarCamara = gcnew Button();
            this->btnCargarImagen = gcnew Button();
            this->comboFiltros = gcnew ComboBox();
            this->trackBar1 = gcnew TrackBar();
            this->timer1 = gcnew Timer();
            this->lblFiltro = gcnew Label();
            this->lblIntensidad = gcnew Label();
            this->lblValorIntensidad = gcnew Label();
            this->panelControles = gcnew Panel();
            this->panelVisor = gcnew Panel();

            // =========================
            // CONFIGURACIÓN DEL FORM
            // =========================
            this->Text = L"OpenCV - Editor de Imágenes";
            this->ClientSize = Drawing::Size(900, 650);
            this->BackColor = Color::FromArgb(240, 240, 245);
            this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
            this->MaximizeBox = false;
            this->StartPosition = FormStartPosition::CenterScreen;
            this->Font = gcnew System::Drawing::Font(L"Segoe UI", 9);

            // =========================
            // PANEL VISOR (Superior)
            // =========================
            panelVisor->Location = Point(20, 20);
            panelVisor->Size = Drawing::Size(860, 500);
            panelVisor->BackColor = Color::FromArgb(45, 45, 48);
            panelVisor->BorderStyle = BorderStyle::None;
            panelVisor->Padding = System::Windows::Forms::Padding(5);

            // PictureBox dentro del panel
            pictureBox1->Location = Point(5, 5);
            pictureBox1->Size = Drawing::Size(850, 490);
            pictureBox1->SizeMode = PictureBoxSizeMode::Zoom;
            pictureBox1->BackColor = Color::FromArgb(30, 30, 30);
            panelVisor->Controls->Add(pictureBox1);

            // =========================
            // PANEL CONTROLES (Inferior)
            // =========================
            panelControles->Location = Point(20, 530);
            panelControles->Size = Drawing::Size(860, 90);
            panelControles->BackColor = Color::White;
            panelControles->BorderStyle = BorderStyle::FixedSingle;

            // Label "Filtro:"
            lblFiltro->Text = L"Filtro:";
            lblFiltro->Location = Point(15, 15);
            lblFiltro->Size = Drawing::Size(50, 25);
            lblFiltro->Font = gcnew System::Drawing::Font(L"Segoe UI Semibold", 10);
            lblFiltro->ForeColor = Color::FromArgb(60, 60, 60);
            panelControles->Controls->Add(lblFiltro);

            // Combo filtros
            comboFiltros->Location = Point(70, 12);
            comboFiltros->Size = Drawing::Size(180, 30);
            comboFiltros->DropDownStyle = ComboBoxStyle::DropDownList;
            comboFiltros->Font = gcnew System::Drawing::Font(L"Segoe UI", 9);
            comboFiltros->FlatStyle = FlatStyle::Flat;
            comboFiltros->BackColor = Color::FromArgb(250, 250, 250);
            comboFiltros->Items->AddRange(gcnew array<String^>{
                "Sin filtro",
                    "Escala de grises",
                    "Binario Blanco/Negro",
                    "Binario Negro/Blanco",
                    "Canny",
                    "Sobel",
                    "Canal Azul",
                    "Canal Verde",
                    "Canal Rojo",
                    "Rotación",
                    "Zoom"
            });
            comboFiltros->SelectedIndex = 0;
            comboFiltros->SelectedIndexChanged += gcnew EventHandler(this, &MainForm::comboFiltros_Changed);
            panelControles->Controls->Add(comboFiltros);

            // Label "Intensidad:"
            lblIntensidad->Text = L"Intensidad:";
            lblIntensidad->Location = Point(270, 15);
            lblIntensidad->Size = Drawing::Size(80, 25);
            lblIntensidad->Font = gcnew System::Drawing::Font(L"Segoe UI Semibold", 10);
            lblIntensidad->ForeColor = Color::FromArgb(60, 60, 60);
            panelControles->Controls->Add(lblIntensidad);

            // TrackBar
            trackBar1->Location = Point(355, 10);
            trackBar1->Size = Drawing::Size(250, 45);
            trackBar1->Minimum = 0;
            trackBar1->Maximum = 100;
            trackBar1->Value = 100;
            trackBar1->TickFrequency = 10;
            trackBar1->TickStyle = TickStyle::BottomRight;
            trackBar1->Scroll += gcnew EventHandler(this, &MainForm::trackBar1_Scroll);
            panelControles->Controls->Add(trackBar1);

            // Label valor intensidad
            lblValorIntensidad->Text = L"100%";
            lblValorIntensidad->Location = Point(615, 15);
            lblValorIntensidad->Size = Drawing::Size(50, 25);
            lblValorIntensidad->Font = gcnew System::Drawing::Font(L"Segoe UI Semibold", 10);
            lblValorIntensidad->ForeColor = Color::FromArgb(0, 120, 215);
            lblValorIntensidad->TextAlign = ContentAlignment::MiddleLeft;
            panelControles->Controls->Add(lblValorIntensidad);

            // =========================
            // BOTONES MODERNOS
            // =========================

            // Botón Abrir Cámara
            btnAbrirCamara->Text = L"📷 Abrir Cámara";
            btnAbrirCamara->Location = Point(15, 50);
            btnAbrirCamara->Size = Drawing::Size(150, 35);
            btnAbrirCamara->BackColor = Color::FromArgb(0, 120, 215);
            btnAbrirCamara->ForeColor = Color::White;
            btnAbrirCamara->FlatStyle = FlatStyle::Flat;
            btnAbrirCamara->FlatAppearance->BorderSize = 0;
            btnAbrirCamara->Font = gcnew System::Drawing::Font(L"Segoe UI Semibold", 10);
            btnAbrirCamara->Cursor = Cursors::Hand;
            btnAbrirCamara->Click += gcnew EventHandler(this, &MainForm::btnAbrirCamara_Click);
            btnAbrirCamara->MouseEnter += gcnew EventHandler(this, &MainForm::btn_MouseEnter);
            btnAbrirCamara->MouseLeave += gcnew EventHandler(this, &MainForm::btn_MouseLeave);
            panelControles->Controls->Add(btnAbrirCamara);

            // Botón Cerrar Cámara
            btnCerrarCamara->Text = L"⏹ Cerrar Cámara";
            btnCerrarCamara->Location = Point(175, 50);
            btnCerrarCamara->Size = Drawing::Size(150, 35);
            btnCerrarCamara->BackColor = Color::FromArgb(232, 17, 35);
            btnCerrarCamara->ForeColor = Color::White;
            btnCerrarCamara->FlatStyle = FlatStyle::Flat;
            btnCerrarCamara->FlatAppearance->BorderSize = 0;
            btnCerrarCamara->Font = gcnew System::Drawing::Font(L"Segoe UI Semibold", 10);
            btnCerrarCamara->Cursor = Cursors::Hand;
            btnCerrarCamara->Click += gcnew EventHandler(this, &MainForm::btnCerrarCamara_Click);
            btnCerrarCamara->MouseEnter += gcnew EventHandler(this, &MainForm::btn_MouseEnter);
            btnCerrarCamara->MouseLeave += gcnew EventHandler(this, &MainForm::btn_MouseLeave);
            panelControles->Controls->Add(btnCerrarCamara);

            // Botón Cargar Imagen
            btnCargarImagen->Text = L"🖼 Cargar Imagen";
            btnCargarImagen->Location = Point(335, 50);
            btnCargarImagen->Size = Drawing::Size(150, 35);
            btnCargarImagen->BackColor = Color::FromArgb(16, 137, 62);
            btnCargarImagen->ForeColor = Color::White;
            btnCargarImagen->FlatStyle = FlatStyle::Flat;
            btnCargarImagen->FlatAppearance->BorderSize = 0;
            btnCargarImagen->Font = gcnew System::Drawing::Font(L"Segoe UI Semibold", 10);
            btnCargarImagen->Cursor = Cursors::Hand;
            btnCargarImagen->Click += gcnew EventHandler(this, &MainForm::btnCargarImagen_Click);
            btnCargarImagen->MouseEnter += gcnew EventHandler(this, &MainForm::btn_MouseEnter);
            btnCargarImagen->MouseLeave += gcnew EventHandler(this, &MainForm::btn_MouseLeave);
            panelControles->Controls->Add(btnCargarImagen);

            // Timer
            timer1->Interval = 30;
            timer1->Tick += gcnew EventHandler(this, &MainForm::timer1_Tick);

            // Agregar paneles al form
            this->Controls->Add(panelVisor);
            this->Controls->Add(panelControles);
        }
#pragma endregion

        // =========================
        // EVENTOS DE HOVER PARA BOTONES
        // =========================
        void btn_MouseEnter(Object^ sender, EventArgs^ e)
        {
            Button^ btn = safe_cast<Button^>(sender);
            btn->FlatAppearance->BorderSize = 2;
            btn->FlatAppearance->BorderColor = Color::White;
        }

        void btn_MouseLeave(Object^ sender, EventArgs^ e)
        {
            Button^ btn = safe_cast<Button^>(sender);
            btn->FlatAppearance->BorderSize = 0;
        }

        // =========================
        // EVENTS
        // =========================

        void btnAbrirCamara_Click(Object^ sender, EventArgs^ e)
        {
            if (!cvManager->camaraActiva)
            {
                cvManager->cap.open(0);
                if (!cvManager->cap.isOpened())
                {
                    MessageBox::Show("No se pudo abrir la cámara", "Error",
                        MessageBoxButtons::OK, MessageBoxIcon::Error);
                    return;
                }

                cvManager->camaraActiva = true;
                timer1->Start();
                btnAbrirCamara->Enabled = false;
                btnCerrarCamara->Enabled = true;
            }
        }

        void btnCerrarCamara_Click(Object^ sender, EventArgs^ e)
        {
            if (cvManager->camaraActiva)
            {
                timer1->Stop();
                cvManager->cap.release();
                cvManager->camaraActiva = false;
                pictureBox1->Image = nullptr;
                btnAbrirCamara->Enabled = true;
                btnCerrarCamara->Enabled = false;
            }
        }

        void btnCargarImagen_Click(Object^ sender, EventArgs^ e)
        {
            OpenFileDialog^ dlg = gcnew OpenFileDialog();
            dlg->Filter = "Imágenes|*.jpg;*.jpeg;*.png;*.bmp";
            dlg->Title = "Seleccionar imagen";

            if (dlg->ShowDialog() == System::Windows::Forms::DialogResult::OK)
            {
                std::string ruta =
                    msclr::interop::marshal_as<std::string>(dlg->FileName);

                cvManager->imagenOriginal = cv::imread(ruta);

                if (cvManager->imagenOriginal.empty())
                {
                    MessageBox::Show("No se pudo cargar la imagen", "Error",
                        MessageBoxButtons::OK, MessageBoxIcon::Error);
                    return;
                }

                cvManager->reprocesarImagen();
                pictureBox1->Image = MatToBitmap(cvManager->imagenProcesada);
            }
        }

        void comboFiltros_Changed(Object^ sender, EventArgs^ e)
        {
            cvManager->filtroActual = (TipoFiltro)comboFiltros->SelectedIndex;
            cvManager->reprocesarImagen();
            pictureBox1->Image = MatToBitmap(cvManager->imagenProcesada);
        }

        void trackBar1_Scroll(Object^ sender, EventArgs^ e)
        {
            // Actualizar label de valor
            lblValorIntensidad->Text = trackBar1->Value.ToString() + "%";

            // Para filtros con intensidad (0-100)
            cvManager->intensidad = trackBar1->Value / 100.0;

            // Para filtros binarios y Canny (0-255)
            cvManager->umbral = (int)(trackBar1->Value * 2.55);

            // Para rotación (0-360 grados)
            cvManager->angulo = (int)(trackBar1->Value * 3.6);

            // Para zoom (0.5x a 3.0x)
            cvManager->zoom = trackBar1->Value / 100.0 * 2.5 + 0.5;

            cvManager->reprocesarImagen();
            pictureBox1->Image = MatToBitmap(cvManager->imagenProcesada);
        }

        void timer1_Tick(Object^ sender, EventArgs^ e)
        {
            if (!cvManager->camaraActiva)
                return;

            cvManager->cap >> cvManager->imagenOriginal;
            if (cvManager->imagenOriginal.empty())
                return;

            cvManager->reprocesarImagen();
            pictureBox1->Image = MatToBitmap(cvManager->imagenProcesada);
        }

        // =========================
        // Mat → Bitmap (FIXED - Corrige colores BGR)
        // =========================
        Bitmap^ MatToBitmap(const cv::Mat& mat)
        {
            if (mat.empty())
                return nullptr;

            cv::Mat rgb;
            if (mat.channels() == 1)
            {
                // Escala de grises a BGR
                cv::cvtColor(mat, rgb, cv::COLOR_GRAY2BGR);
            }
            else if (mat.channels() == 3)
            {
                // Ya está en BGR, solo hacer una copia
                rgb = mat.clone();
            }
            else
            {
                return nullptr;
            }

            Bitmap^ bmp = gcnew Bitmap(
                rgb.cols,
                rgb.rows,
                PixelFormat::Format24bppRgb
            );

            BitmapData^ data = bmp->LockBits(
                System::Drawing::Rectangle(0, 0, bmp->Width, bmp->Height),
                ImageLockMode::WriteOnly,
                PixelFormat::Format24bppRgb
            );

            // Copiar datos invirtiendo el orden de bytes (BGR -> RGB)
            for (int y = 0; y < rgb.rows; y++)
            {
                unsigned char* srcRow = rgb.ptr(y);
                unsigned char* dstRow = (unsigned char*)data->Scan0.ToPointer() + y * data->Stride;

                for (int x = 0; x < rgb.cols; x++)
                {
                    // Invertir BGR a RGB
                    dstRow[x * 3 + 0] = srcRow[x * 3 + 2]; // R
                    dstRow[x * 3 + 1] = srcRow[x * 3 + 1]; // G
                    dstRow[x * 3 + 2] = srcRow[x * 3 + 0]; // B
                }
            }

            bmp->UnlockBits(data);
            return bmp;
        }
    };
}