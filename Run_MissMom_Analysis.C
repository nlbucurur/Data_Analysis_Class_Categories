void Run_MissMom_Analysis()
{
    // Load header and source files dynamically
    gROOT->ProcessLine(".L BDT.h++");
    gROOT->ProcessLine(".L config.C");
    gROOT->ProcessLine(".L Training_on_bins_MissP.C++");

    // Create object and run in the interpreter
    gROOT->ProcessLine("BDT l;");
    gROOT->ProcessLine("l.config();");
    gROOT->ProcessLine("l.Training_on_bins_MissP(l.Data);");
}